#include "Lexer.h"
#include "NumberSystem/NumberSystemExtensions/NumberSystemExtensions.h"
#include "Token/TokenInformation/TokenInformation.h"
#include <set>

Lexer::Lexer(std::string const & inputFileName)
	: m_inputFileName(inputFileName)
	, m_input(inputFileName)
{}

Lexer::Lexer(std::istream & is)
	: m_inputFileName("")
	, m_input(is)
{}

bool Lexer::GetNextTokenInformation(TokenInformation & tokenInformation)
{
	return PopNextTokenInformation(tokenInformation) || DetermineNextTokenInformation(tokenInformation);
}

bool Lexer::PopNextTokenInformation(TokenInformation & tokenInformation)
{
	if (!m_tokenInformations.empty())
	{
		tokenInformation = m_tokenInformations.front();
		m_tokenInformations.erase(m_tokenInformations.begin());
		return true;
	}
	return false;
}

bool Lexer::DetermineNextTokenInformation(TokenInformation & tokenInformation)
{
	StreamString scanned;
	StreamString delimiter;
	std::string lastScannedString;
	while (m_input.Scan(SCANNER_DELIMITERS, scanned, delimiter))
	{
		if (TryToSkipComment(delimiter.string))
		{
			continue;
		}
		else if (TryToCreateLiteral(delimiter.string, delimiter.string))
		{
		}

		scanned.string.insert(
			scanned.string.begin(),
			std::make_move_iterator(lastScannedString.begin()),
			std::make_move_iterator(lastScannedString.end()));
		if (NeedMoreScanning(scanned.string, delimiter.string))
		{
			lastScannedString = move(scanned.string);
			lastScannedString.insert(
				lastScannedString.end(),
				std::make_move_iterator(delimiter.string.begin()),
				std::make_move_iterator(delimiter.string.end()));
			continue;
		}
		bool tokenDetermined = false;
		if (!scanned.string.empty())
		{
			Token scannedStringToken;
			DetermineScannedStringToken(scanned.string, scannedStringToken);
			m_tokenInformations.emplace_back(TokenInformation(scannedStringToken, scanned, m_inputFileName));
			tokenDetermined = true;
		}
		if (DELIMITERS_TO_SKIP.find(delimiter.string) == DELIMITERS_TO_SKIP.end())
		{
			Token delimiterToken;
			DetermineDelimiterToken(delimiter.string, delimiterToken);
			m_tokenInformations.emplace_back(TokenInformation(delimiterToken, delimiter, m_inputFileName));
			tokenDetermined = true;
		}
		if (tokenDetermined)
		{
			break;
		}
	}
	if (m_tokenInformations.empty())
	{
		return false;
	}
	return PopNextTokenInformation(tokenInformation);
}

bool Lexer::TryToSkipComment(std::string const & delimiterString)
{
	if (delimiterString == Constant::Comment::LINE)
	{
		m_input.SkipLine();
		return true;
	}
	if (delimiterString == Constant::Comment::BLOCK_BEGINNING)
	{
		SkipBlockComment();
		return true;
	}
	return false;
}

bool Lexer::TryToCreateLiteral(std::string const & delimiterString, std::string & literal)
{
	char wrapper = 0;
	if (delimiterString == Constant::Parentheses::DOUBLE_QUOTE_STRING)
	{
		wrapper = Constant::Parentheses::DOUBLE_QUOTE_CHARACTER;
	}
	else if (delimiterString == Constant::Parentheses::QUOTE_STRING)
	{
		wrapper = Constant::Parentheses::QUOTE_CHARACTER;
	}
	if (wrapper != 0 && m_input.SkipUntilCharacters({ wrapper }, literal))
	{
		literal.insert(literal.begin(), wrapper);
		literal.insert(literal.end(), wrapper);
		m_input.SkipArgument<char>();
		return true;
	}
	return false;
}

bool Lexer::NeedMoreScanning(std::string const & scannedString, std::string const & delimiter)
{
	Token token;
	return !scannedString.empty()
		&& ((delimiter == Constant::Separator::DOT && DetermineNumberToken(scannedString, token))
			|| (scannedString.back() == Constant::Separator::EXPONENT_CHARACTER
				&& scannedString.at(scannedString.length() - 2) == Constant::Separator::UNDERSCORE_CHARACTER
				&& (delimiter == Constant::Operator::Arithmetic::PLUS
					|| delimiter == Constant::Operator::Arithmetic::MINUS)
				&& DetermineNumberToken(scannedString.substr(0, scannedString.length() - 2), token)));
}

void Lexer::SkipBlockComment()
{
	std::string skippedString;
	if (m_input.SkipUntilStrings({ Constant::Comment::BLOCK_ENDING }, skippedString))
	{
		m_input.SkipArguments<char>(Constant::Comment::BLOCK_ENDING.length());
	}
}

bool Lexer::DetermineScannedStringToken(std::string const & scannedString, Token & token)
{
	token = Token::UNKNOWN;
	if (scannedString.empty())
	{
		return false;
	}
	if (IsIdentifier(scannedString))
	{
		token = Token::IDENTIFIER;
		if (TokenExtensions::TryToGetKeywordToken(scannedString, token)
			|| TokenExtensions::TryToGetTypeToken(scannedString, token))
		{
		}
		return true;
	}
	return DetermineNumberToken(scannedString, token);
}

bool Lexer::IsIdentifier(std::string const & str)
{
	return std::regex_match(str.begin(), str.end(), Constant::Regex::IDENTIFIER);
}

bool Lexer::IsDigit(char ch, NumberSystem numberSystem)
{
	std::set<char> availableCharacters;
	NumberSystemExtensions::CreateAvailableCharacters(numberSystem, availableCharacters);
	return availableCharacters.find(ch) != availableCharacters.end();
}

bool Lexer::IsInteger(
	std::string const & str, size_t fromIndex, size_t & failIndex, std::string & goodString, NumberSystem numberSystem)
{
	if (str.empty() || fromIndex > str.length() - 1)
	{
		return false;
	}
	for (size_t i = fromIndex; i < str.length(); ++i)
	{
		if (!IsDigit(str.at(i), numberSystem))
		{
			failIndex = i;
			goodString = std::move(str.substr(fromIndex, i - fromIndex));
			return false;
		}
	}
	return true;
}

bool Lexer::DetermineNumberToken(std::string const & scannedString, Token & token)
{
	if (scannedString.empty() || !IsDigit(scannedString.front()))
	{
		return false;
	}

	size_t failIndex;
	std::string goodString;
	if (IsInteger(scannedString, 0, failIndex, goodString))
	{
		token = Token::INTEGER;
		return true;
	}

	if (scannedString.at(failIndex) == Constant::Separator::DOT_CHARACTER)
	{
		if (IsInteger(scannedString, failIndex + 1, failIndex, goodString))
		{
			token = Token::FLOAT;
			return true;
		}
	}

	if (scannedString.at(failIndex) == Constant::Separator::UNDERSCORE_CHARACTER)
	{
		if (scannedString.length() > failIndex + 1
			&& scannedString.at(failIndex + 1) == Constant::Separator::EXPONENT_CHARACTER)
		{
			if (scannedString.length() > failIndex + 2)
			{
				char nextChar = scannedString.at(failIndex + 2);
				if (nextChar == Constant::Operator::Arithmetic::PLUS_CHARACTER
					|| nextChar == Constant::Operator::Arithmetic::MINUS_CHARACTER)
				{
					if (IsInteger(scannedString, failIndex + 3, failIndex, goodString))
					{
						token = Token::EXPONENTIAL;
						return true;
					}

					if (scannedString.at(failIndex) == Constant::Separator::DOT_CHARACTER)
					{
						if (IsInteger(scannedString, failIndex + 1, failIndex, goodString))
						{
							token = Token::EXPONENTIAL;
							return true;
						}
					}
				}
			}
		}

		NumberSystem numberSystem;
		if (!NumberSystemExtensions::CreateFromString(goodString, numberSystem))
		{
			token = Token::UNKNOWN;
			return false;
		}

		if (IsInteger(scannedString, failIndex + 1, failIndex, goodString, numberSystem))
		{
			token = Token::INTEGER;
			return true;
		}

		if (scannedString.at(failIndex) == Constant::Separator::DOT_CHARACTER)
		{
			if (IsInteger(scannedString, failIndex + 1, failIndex, goodString, numberSystem))
			{
				token = Token::FLOAT;
				return true;
			}
		}

		if (scannedString.at(failIndex) == Constant::Separator::UNDERSCORE_CHARACTER)
		{
			if (scannedString.length() > failIndex + 1
				&& scannedString.at(failIndex + 1) == Constant::Separator::EXPONENT_CHARACTER)
			{
				if (scannedString.length() > failIndex + 2)
				{
					char nextChar = scannedString.at(failIndex + 2);
					if (nextChar == Constant::Operator::Arithmetic::PLUS_CHARACTER
						|| nextChar == Constant::Operator::Arithmetic::MINUS_CHARACTER)
					{
						if (IsInteger(scannedString, failIndex + 3, failIndex, goodString))
						{
							token = Token::EXPONENTIAL;
							return true;
						}

						if (scannedString.at(failIndex) == Constant::Separator::DOT_CHARACTER)
						{
							if (IsInteger(scannedString, failIndex + 1, failIndex, goodString))
							{
								token = Token::EXPONENTIAL;
								return true;
							}
						}
					}
				}
			}
		}
	}
	token = Token::UNKNOWN;
	return false;
}

bool Lexer::DetermineDelimiterToken(std::string const & delimiterString, Token & token)
{
	token = Token::UNKNOWN;
	return TryToAddLiteralToken(delimiterString, token)
		|| TokenExtensions::TryToGetDelimiterToken(delimiterString, token);
}

bool Lexer::TryToAddLiteralToken(std::string const & delimiterString, Token & token)
{
	if (delimiterString.front() == Constant::Parentheses::QUOTE_CHARACTER && delimiterString.length() == 3)
	{
		token = Token::CHARACTER_LITERAL;
		return true;
	}
	else if (delimiterString.front() == Constant::Parentheses::DOUBLE_QUOTE_CHARACTER)
	{
		token = Token::STRING_LITERAL;
		return true;
	}
	return false;
}

std::unordered_set<std::string> const Lexer::DELIMITERS_TO_SKIP {
	"",
	Constant::Separator::SPACE,
	Constant::Separator::TAB,
	Constant::Separator::END_OF_LINE_LF,
	Constant::Separator::END_OF_LINE_CR
};
