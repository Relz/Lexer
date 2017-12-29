#include "Lexer.h"

Lexer::Lexer(const std::string & inputFileName)
		: _inputFileName(inputFileName)
		, _input(inputFileName)
{
	std::string scannedString;
	Position scannedStringPosition {};
	std::string delimiter;
	Position delimiterPosition {};
	std::string lastScannedString;
	while (_input.Scan(SCANNER_DELIMITERS, scannedString, scannedStringPosition, delimiter, delimiterPosition))
	{
		Token delimiterToken = Token::UNKNOWN;
		bool delimiterTokenDetermined = false;
		if (delimiter == Constant::Comment::LINE)
		{
			_input.SkipLine();
		}
		else if (delimiter == Constant::Comment::BLOCK_BEGINNING)
		{
			SkipBlockComment();
		}
		else if (delimiter == Constant::Parentheses::DOUBLE_QUOTE)
		{
			if (_input.SkipUntilStrings({Constant::Parentheses::DOUBLE_QUOTE}, delimiter))
			{
				delimiter.insert(delimiter.begin(), Constant::Parentheses::DOUBLE_QUOTE_CHARACTER);
				delimiter.insert(delimiter.end(), Constant::Parentheses::DOUBLE_QUOTE_CHARACTER);
				_input.SkipArgument<char>();
				delimiterToken = Token::STRING_LITERAL;
			}
			else
			{
				delimiterToken = Token::UNKNOWN;
			}
			delimiterTokenDetermined = true;
		}
		else if (delimiter == Constant::Parentheses::QUOTE_STRING)
		{
			char ch;
			char expectedQuote;
			_input.ReadArguments(ch, expectedQuote);
			if (expectedQuote == Constant::Parentheses::QUOTE_CHARACTER)
			{
				delimiter.insert(delimiter.end(), ch);
				delimiter.insert(delimiter.end(), Constant::Parentheses::QUOTE_CHARACTER);
				delimiterToken = Token::CHARACTER_LITERAL;
			}
			else
			{
				delimiterToken = Token::UNKNOWN;
			}
			delimiterTokenDetermined = true;
		}
		if (!Skip(scannedString, delimiter))
		{
			scannedString.insert(scannedString.begin(), lastScannedString.begin(), lastScannedString.end());
			if (NeedMoreScanning(scannedString, delimiter))
			{
				lastScannedString = scannedString + delimiter;
				continue;
			}
			lastScannedString.clear();
			TokenUtils::DetermineTokens(
				scannedString,
				scannedStringPosition,
				delimiter,
				delimiterPosition,
				delimiterToken,
				delimiterTokenDetermined,
				_tokenInfos
			);
		}
	}
}

void Lexer::Print()
{
	for (TokenInfo & tokenInfo : _tokenInfos)
	{
		tokenInfo.SetFileName(_inputFileName);
		std::cout << tokenInfo.ToString() << "\n";
	}
}

bool Lexer::Skip(const std::string & scannedString, const std::string & delimiter)
{
	return SCANNER_SKIPS.find(scannedString) != SCANNER_SKIPS.end()
		   && SCANNER_SKIPS.at(scannedString).find(delimiter) != SCANNER_SKIPS.at(scannedString).end();
}

bool Lexer::NeedMoreScanning(const std::string & scannedString, const std::string & delimiter)
{
	return
		!scannedString.empty()
		&&
		(
			(
				Rule::IsDigit(scannedString.back())
				&& delimiter == Constant::Separator::DOT
			)
			||
			(
				scannedString.back() == Constant::Separator::EXPONENT_CHARACTER
				&& delimiter == Constant::Operator::Arithmetic::PLUS
			)
			||
			(
				scannedString.back() == Constant::Separator::EXPONENT_CHARACTER
				&& delimiter == Constant::Operator::Arithmetic::MINUS
			)
		);
}

void Lexer::SkipBlockComment()
{
	std::string skippedString;
	if (_input.SkipUntilStrings({Constant::Comment::BLOCK_ENDING}, skippedString))
	{
		_input.SkipArguments<char>(Constant::Comment::BLOCK_ENDING.length());
	}
}

const std::unordered_map<std::string, std::unordered_set<std::string>> Lexer::SCANNER_SKIPS = {
		{
			"",
			{
				"",
				Constant::Separator::SPACE,
				Constant::Separator::TAB,
				Constant::Separator::END_OF_LINE_LF,
				Constant::Separator::END_OF_LINE_CR,
				Constant::Separator::END_OF_LINE_CRLF
			}
		}
};
