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

class Lexer
{
public:
	explicit Lexer(std::string const& inputFileName)
		: m_inputFileName(inputFileName)
		, m_input(inputFileName)
	{}

	bool GetNextTokenInformation(TokenInformation & tokenInformation)
	{
		if (!m_tokenInformations.empty())
		{
			tokenInformation = m_tokenInformations.front();
			m_tokenInformations.erase(m_tokenInformations.begin());
			return true;
		}
		bool result = false;
		StreamString scanned;
		StreamString delimiter;
		std::string lastScannedString;
		while (m_input.Scan(SCANNER_DELIMITERS, scanned, delimiter))
		{
			result = true;
			if (TryToSkipComment(delimiter.string)) {}
			else if (TryToCreateLiteral(delimiter.string, delimiter.string)) {}

			if (!Skip(scanned.string, delimiter.string))
			{
				scanned.string.insert(
					scanned.string.begin(),
					std::make_move_iterator(lastScannedString.begin()),
					std::make_move_iterator(lastScannedString.end())
				);
				if (NeedMoreScanning(scanned.string, delimiter.string))
				{
					lastScannedString = move(scanned.string);
					lastScannedString.insert(lastScannedString.end(), make_move_iterator(delimiter.string.begin()), make_move_iterator(delimiter.string.end()));
					continue;
				}
				Token scannedStringToken;
				TokenUtils::DetermineScannedStringToken(scanned.string, scannedStringToken);
				m_tokenInformations.emplace_back(TokenInformation(scannedStringToken, scanned, m_inputFileName));

				Token delimiterToken;
				TokenUtils::DetermineDelimiterToken(delimiter.string, delimiterToken);
				m_tokenInformations.emplace_back(TokenInformation(delimiterToken, delimiter, m_inputFileName));
				break;
			}
		}
		return result;
	}

private:
	static std::unordered_map<std::string, std::unordered_set<std::string>> const SCANNER_SKIPS;

	Input m_input;
	std::string const m_inputFileName;
	std::vector<TokenInformation> m_tokenInformations;

	bool TryToSkipComment(std::string const& delimiterString)
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

	bool TryToCreateLiteral(std::string const& delimiterString, std::string & literal)
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

	bool Skip(std::string const& scannedString, std::string const& delimiterString)
	{
		return SCANNER_SKIPS.find(scannedString) != SCANNER_SKIPS.end()
			&& SCANNER_SKIPS.at(scannedString).find(delimiterString) != SCANNER_SKIPS.at(scannedString).end();
	}
	bool NeedMoreScanning(std::string const& scannedString, std::string const& delimiter)
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
		std::string skippedString;
		if (m_input.SkipUntilStrings({ Constant::Comment::BLOCK_ENDING }, skippedString))
		{
			m_input.SkipArguments<char>(Constant::Comment::BLOCK_ENDING.length());
		}
	}
};

std::unordered_map<std::string, std::unordered_set<std::string>> const Lexer::SCANNER_SKIPS
{
	{
		"",
		{
			"",
			Constant::Separator::SPACE,
			Constant::Separator::TAB,
			Constant::Separator::END_OF_LINE_LF,
			Constant::Separator::END_OF_LINE_CR
		}
	}
};

#endif //LEXER_LEXER_H
