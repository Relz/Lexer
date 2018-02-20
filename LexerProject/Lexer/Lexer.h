#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "Constant.h"
#include "InputSolution/Input/Input.h"
#include "Token/TokenInformation.h"
#include "Token/TokenUtils.h"

using namespace std;

class Lexer
{
public:
	explicit Lexer(string const& inputFileName)
			: m_inputFileName(inputFileName)
			, m_input(inputFileName)
	{
		string scannedString;
		StreamPosition scannedStringPosition { };
		string delimiter;
		StreamPosition delimiterPosition { };
		string lastScannedString;
		while (m_input.Scan(SCANNER_DELIMITERS, scannedString, scannedStringPosition, delimiter, delimiterPosition))
		{
			Token delimiterToken = Token::UNKNOWN;
			bool delimiterTokenDetermined = false;
			if (delimiter == Constant::Comment::LINE)
			{
				m_input.SkipLine();
			}
			else if (delimiter == Constant::Comment::BLOCK_BEGINNING)
			{
				SkipBlockComment();
			}
			else if (delimiter == Constant::Parentheses::DOUBLE_QUOTE)
			{
				if (m_input.SkipUntilStrings({ Constant::Parentheses::DOUBLE_QUOTE }, delimiter))
				{
					delimiter.insert(delimiter.begin(), Constant::Parentheses::DOUBLE_QUOTE_CHARACTER);
					delimiter.insert(delimiter.end(), Constant::Parentheses::DOUBLE_QUOTE_CHARACTER);
					m_input.SkipArgument<char>();
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
				m_input.ReadArguments(ch, expectedQuote);
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
					m_tokenInformations
				);
			}
		}
	}

	void Print()
	{
		for (TokenInformation & tokenInfo : m_tokenInformations)
		{
			tokenInfo.SetFileName(m_inputFileName);
			cout << tokenInfo.ToString() << "\n";
		}
	}

private:
	static const unordered_map<string, unordered_set<string>> SCANNER_SKIPS;

	CInput m_input;
	const string m_inputFileName;
	vector<TokenInformation> m_tokenInformations;

	bool Skip(string const& scannedString, string const& delimiter)
	{
		return SCANNER_SKIPS.find(scannedString) != SCANNER_SKIPS.end()
			&& SCANNER_SKIPS.at(scannedString).find(delimiter) != SCANNER_SKIPS.at(scannedString).end();
	}
	bool NeedMoreScanning(string const& scannedString, string const& delimiter)
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
					&&
					(
						delimiter == Constant::Operator::Arithmetic::PLUS
						|| delimiter == Constant::Operator::Arithmetic::MINUS
					)
				)
			);
	}
	void SkipBlockComment()
	{
		string skippedString;
		if (m_input.SkipUntilStrings({ Constant::Comment::BLOCK_ENDING }, skippedString))
		{
			m_input.SkipArguments<char>(Constant::Comment::BLOCK_ENDING.length());
		}
	}
};

const unordered_map<string, unordered_set<string>> Lexer::SCANNER_SKIPS
{
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

#endif //LEXER_LEXER_H
