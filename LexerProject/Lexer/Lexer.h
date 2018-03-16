#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include "Constant.h"
#include "InputSolution/Input/Input.h"
#include "NumberSystem/NumberSystemExtensions.h"
#include "Token/TokenInformation.h"
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Lexer
{
public:
	explicit Lexer(std::string const & inputFileName)
		: m_inputFileName(inputFileName)
		, m_input(inputFileName)
	{}

	bool GetNextTokenInformation(TokenInformation & tokenInformation)
	{
		return PopNextTokenInformation(tokenInformation) || DetermineNextTokenInformation(tokenInformation);
	}

private:
	static std::unordered_set<std::string> const DELIMITERS_TO_SKIP;

	Input m_input;
	std::string const m_inputFileName;
	std::vector<TokenInformation> m_tokenInformations;

	bool PopNextTokenInformation(TokenInformation & tokenInformation)
	{
		if (!m_tokenInformations.empty())
		{
			tokenInformation = m_tokenInformations.front();
			m_tokenInformations.erase(m_tokenInformations.begin());
			return true;
		}
		return false;
	}

	bool DetermineNextTokenInformation(TokenInformation & tokenInformation)
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
			if (!scanned.string.empty())
			{
				Token scannedStringToken;
				DetermineScannedStringToken(scanned.string, scannedStringToken);
				m_tokenInformations.emplace_back(TokenInformation(scannedStringToken, scanned, m_inputFileName));
				break;
			}
			if (DELIMITERS_TO_SKIP.find(delimiter.string) == DELIMITERS_TO_SKIP.end())
			{
				Token delimiterToken;
				DetermineDelimiterToken(delimiter.string, delimiterToken);
				m_tokenInformations.emplace_back(TokenInformation(delimiterToken, delimiter, m_inputFileName));
				break;
			}
		}
		if (m_tokenInformations.empty())
		{
			return false;
		}
		return PopNextTokenInformation(tokenInformation);
	}

	bool TryToSkipComment(std::string const & delimiterString)
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

	bool TryToCreateLiteral(std::string const & delimiterString, std::string & literal)
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

	bool NeedMoreScanning(std::string const & scannedString, std::string const & delimiter)
	{
		return !scannedString.empty()
			&& ((IsDigit(scannedString.back()) && delimiter == Constant::Separator::DOT)
				|| (scannedString.back() == Constant::Separator::EXPONENT_CHARACTER
					&& (delimiter == Constant::Operator::Arithmetic::PLUS
						|| delimiter == Constant::Operator::Arithmetic::MINUS)));
	}

	void SkipBlockComment()
	{
		std::string skippedString;
		if (m_input.SkipUntilStrings({ Constant::Comment::BLOCK_ENDING }, skippedString))
		{
			m_input.SkipArguments<char>(Constant::Comment::BLOCK_ENDING.length());
		}
	}

	static bool DetermineScannedStringToken(std::string const & scannedString, Token & token)
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

	static bool IsIdentifier(std::string const & str)
	{
		return std::regex_match(str.begin(), str.end(), Constant::Regex::IDENTIFIER);
	}

	static bool IsDigit(char ch, NumberSystem numberSystem = DEFAULT_NUMBER_SYSTEM)
	{
		std::set<char> availableCharacters;
		NumberSystemExtensions::CreateAvailableCharacters(numberSystem, availableCharacters);
		return availableCharacters.find(ch) != availableCharacters.end();
	}

	static bool IsInteger(
		std::string const & str,
		size_t fromIndex,
		size_t & failIndex,
		std::string & goodString,
		NumberSystem numberSystem = DEFAULT_NUMBER_SYSTEM)
	{
		if (str.empty())
		{
			return true;
		}
		size_t i = fromIndex;
		for (i; i < str.length(); ++i)
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

	static bool DetermineNumberToken(std::string const & scannedString, Token & token)
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
		else if (scannedString.at(failIndex) == Constant::Separator::UNDERSCORE_CHARACTER)
		{
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
		}

		if (scannedString.at(failIndex) == Constant::Separator::EXPONENT_CHARACTER)
		{
			if (scannedString.length() > failIndex + 1)
			{
				char nextChar = scannedString.at(failIndex + 1);
				if (nextChar == Constant::Operator::Arithmetic::PLUS_CHARACTER
					|| nextChar == Constant::Operator::Arithmetic::MINUS_CHARACTER)
				{
					if (IsInteger(scannedString, failIndex + 2, failIndex, goodString))
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
		token = Token::UNKNOWN;
		return false;
	}

	static bool DetermineDelimiterToken(std::string const & delimiterString, Token & token)
	{
		token = Token::UNKNOWN;
		return TryToAddLiteralToken(delimiterString, token)
			|| TokenExtensions::TryToGetDelimiterToken(delimiterString, token);
	}

	static bool TryToAddLiteralToken(std::string const & scannedString, Token & token)
	{
		if (scannedString.front() == Constant::Parentheses::QUOTE_CHARACTER)
		{
			token = Token::CHARACTER_LITERAL;
			return true;
		}
		else if (scannedString.front() == Constant::Parentheses::DOUBLE_QUOTE_CHARACTER)
		{
			token = Token::STRING_LITERAL;
			return true;
		}
		return false;
	}
};

std::unordered_set<std::string> const Lexer::DELIMITERS_TO_SKIP {
	Constant::Separator::SPACE,
	Constant::Separator::TAB,
	Constant::Separator::END_OF_LINE_LF,
	Constant::Separator::END_OF_LINE_CR
};

#endif //LEXER_LEXER_H
