#ifndef TOKEN_TOKENUTILS_H
#define TOKEN_TOKENUTILS_H

#include <string>
#include <stdexcept>
#include <unordered_map>
#include "Constant/Constant.h"
#include "Rule.h"
#include "Token.h"
#include "TokenInfo.h"

namespace
{
	class TokenUtils
	{
	public:
		static void DetermineTokens(
			const std::string & scannedString,
			Position scannedStringPosition,
			const std::string & delimiter,
			Position delimiterPosition,
			Token delimiterToken,
			bool delimiterTokenDetermined,
			std::vector<TokenInfo> & tokenInfos
		)
		{
			bool skipDelimiterDetermining = (_delimitersToSkip.find(delimiter) != _delimitersToSkip.end());

			if (!scannedString.empty())
			{
				Token scannedStringToken;
				DetermineScannedStringToken(scannedString, scannedStringToken);
				tokenInfos.emplace_back(TokenInfo(scannedStringToken, scannedString, scannedStringPosition));
			}

			if (!skipDelimiterDetermining)
			{
				if (!delimiterTokenDetermined)
				{
					DetermineDelimiterToken(delimiter, delimiterToken);
				}
				tokenInfos.emplace_back(TokenInfo(delimiterToken, delimiter, delimiterPosition));
			}
		}

	private:
		static bool TryAddTokenAt(
			const std::unordered_map<std::string, Token> & unorderedMap,
			const std::string & searchStr,
			Token & token
		)
		{
			if (unorderedMap.find(searchStr) == unorderedMap.end())
			{
				return false;
			}
			token = unorderedMap.at(searchStr);
			return true;
		}

		static bool TryAddTypeAt(const std::string & searchStr, Token & token)
		{
			if (_types.find(searchStr) != _types.end())
			{
				token = Token::TYPE;
				return true;
			}
			else
			{
				return false;
			}
		}

		static bool DetermineScannedStringToken(const std::string & scannedString, Token & token)
		{
			if (!scannedString.empty())
			{
				if (Rule::IsIdentifier(scannedString))
				{
					if (
						TryAddTokenAt(_stringsToKeywordTokens, scannedString, token)
						|| TryAddTypeAt(scannedString, token)
					)
					{
						return true;
					}
					token = Token::IDENTIFIER;
					return true;
				}

				if (DetermineNumberToken(scannedString, token))
				{
					return true;
				}
			}
			token = Token::UNKNOWN;
		}

		static bool DetermineDelimiterToken(const std::string & delimiter, Token & token)
		{
			if (
				TryAddTokenAt(_stringsToComparisonOperatorTokens, delimiter, token)
				|| TryAddTokenAt(_stringsToAssignmentOperatorTokens, delimiter, token)
				|| TryAddTokenAt(_stringsToArithmeticOperatorTokens, delimiter, token)
				|| TryAddTokenAt(_stringsToSeparatorTokens, delimiter, token)
				|| TryAddTokenAt(_stringsToParenthesisTokens, delimiter, token)
			)
			{
				return true;
			}
			token = Token::UNKNOWN;
			return false;
		}

		static bool DetermineNumberToken(const std::string & scannedString, Token & token)
		{
			if (scannedString.empty() || !Rule::IsDigit(scannedString.front()))
			{
				return false;
			}

			size_t failIndex;
			std::string goodString;
			if (Rule::IsInteger(scannedString, 0, failIndex, goodString))
			{
				token = Token::INTEGER;
				return true;
			}

			if (scannedString.at(failIndex) == Constant::Separator::DOT_CHARACTER)
			{
				if (Rule::IsInteger(scannedString, failIndex + 1, failIndex, goodString))
				{
					token = Token::FLOAT;
					return true;
				}
			}
			else if (scannedString.at(failIndex) == Constant::Separator::UNDERSCORE_CHARACTER)
			{
				size_t numberSystem;
				try
				{
					numberSystem = std::stoul(goodString);
					if (numberSystem > Constant::Number::MAX_SYSTEM)
					{
						throw std::exception();
					}
				}
				catch (...)
				{
					token = Token::UNKNOWN;
					return false;
				}
				if (Rule::IsInteger(scannedString, failIndex + 1, failIndex, goodString, numberSystem))
				{
					token = Token::INTEGER;
					return true;
				}

				if (scannedString.at(failIndex) == Constant::Separator::DOT_CHARACTER)
				{
					if (Rule::IsInteger(scannedString, failIndex + 1, failIndex, goodString))
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
						if (Rule::IsInteger(scannedString, failIndex + 2, failIndex, goodString))
						{
							token = Token::EXPONENTIAL;
							return true;
						}

						if (scannedString.at(failIndex) == Constant::Separator::DOT_CHARACTER)
						{
							if (Rule::IsInteger(scannedString, failIndex + 1, failIndex, goodString))
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

		static const std::unordered_map<std::string, Token> _stringsToArithmeticOperatorTokens;

		static const std::unordered_map<std::string, Token> _stringsToAssignmentOperatorTokens;

		static const std::unordered_map<std::string, Token> _stringsToComparisonOperatorTokens;

		static const std::unordered_map<std::string, Token> _stringsToSeparatorTokens;

		static const std::unordered_map<std::string, Token> _stringsToParenthesisTokens;

		static const std::unordered_map<std::string, Token> _stringsToKeywordTokens;

		static const std::unordered_set<std::string> _types;

		static const std::unordered_set<std::string> _delimitersToSkip;
	};
}

const std::unordered_map<std::string, Token> TokenUtils::_stringsToArithmeticOperatorTokens
{
	{Constant::Operator::Arithmetic::DIVISION, Token::DIVISION},
	{Constant::Operator::Arithmetic::MINUS,    Token::MINUS},
	{Constant::Operator::Arithmetic::MULTIPLY, Token::MULTIPLY},
	{Constant::Operator::Arithmetic::PLUS,     Token::PLUS}
};

const std::unordered_map<std::string, Token> TokenUtils::_stringsToAssignmentOperatorTokens
{
	{Constant::Operator::Assignment::ASSIGNMENT,          Token::ASSIGNMENT},
	{Constant::Operator::Assignment::PLUS_ASSIGNMENT,     Token::PLUS_ASSIGNMENT},
	{Constant::Operator::Assignment::MINUS_ASSIGNMENT,    Token::MINUS_ASSIGNMENT},
	{Constant::Operator::Assignment::MULTIPLY_ASSIGNMENT, Token::MULTIPLY_ASSIGNMENT},
	{Constant::Operator::Assignment::DIVISION_ASSIGNMENT, Token::DIVISION_ASSIGNMENT}
};

const std::unordered_map<std::string, Token> TokenUtils::_stringsToComparisonOperatorTokens
{
	{Constant::Operator::Comparison::EQUIVALENCE,         Token::EQUIVALENCE},
	{Constant::Operator::Comparison::NOT_EQUIVALENCE,     Token::NOT_EQUIVALENCE},
	{Constant::Operator::Comparison::MORE_OR_EQUIVALENCE, Token::MORE_OR_EQUIVALENCE},
	{Constant::Operator::Comparison::LESS_OR_EQUIVALENCE, Token::LESS_OR_EQUIVALENCE},
	{Constant::Operator::Comparison::MORE,                Token::MORE},
	{Constant::Operator::Comparison::LESS,                Token::LESS}
};

const std::unordered_map<std::string, Token> TokenUtils::_stringsToSeparatorTokens
{
	{Constant::Separator::COLON,     Token::COLON},
	{Constant::Separator::COMMA,     Token::COMMA},
	{Constant::Separator::DOT,       Token::DOT},
	{Constant::Separator::SEMICOLON, Token::SEMICOLON}
};

const std::unordered_map<std::string, Token> TokenUtils::_stringsToParenthesisTokens
{
	{Constant::Parentheses::ANGLE_BRACKET.LEFT,   Token::LEFT_ANGLE_BRACKET},
	{Constant::Parentheses::ANGLE_BRACKET.RIGHT,  Token::RIGHT_ANGLE_BRACKET},
	{Constant::Parentheses::CURLY_BRACKET.LEFT,   Token::LEFT_CURLY_BRACKET},
	{Constant::Parentheses::CURLY_BRACKET.RIGHT,  Token::RIGHT_CURLY_BRACKET},
	{Constant::Parentheses::ROUND_BRACKET.LEFT,   Token::LEFT_ROUND_BRACKET},
	{Constant::Parentheses::ROUND_BRACKET.RIGHT,  Token::RIGHT_ROUND_BRACKET},
	{Constant::Parentheses::SQUARE_BRACKET.LEFT,  Token::LEFT_SQUARE_BRACKET},
	{Constant::Parentheses::SQUARE_BRACKET.RIGHT, Token::RIGHT_SQUARE_BRACKET}
};

const std::unordered_map<std::string, Token> TokenUtils::_stringsToKeywordTokens
{
	{Constant::Keyword::CLASS,           Token::CLASS},
	{Constant::Keyword::CONSTRUCTOR,     Token::CONSTRUCTOR},
	{Constant::Keyword::DO,              Token::DO},
	{Constant::Keyword::EXTENDS,         Token::EXTENDS},
	{Constant::Keyword::FOR,             Token::FOR},
	{Constant::Keyword::GET,             Token::GET},
	{Constant::Keyword::IMPLEMENTS,      Token::IMPLEMENTS},
	{Constant::Keyword::NOT_INITIALIZED, Token::NOT_INITIALIZED},
	{Constant::Keyword::PRIVATE,         Token::PRIVATE},
	{Constant::Keyword::PUBLIC,          Token::PUBLIC},
	{Constant::Keyword::SET,             Token::SET},
	{Constant::Keyword::RETURN,          Token::RETURN},
	{Constant::Keyword::WHILE,           Token::WHILE},
	{Constant::Keyword::IF,              Token::IF},
	{Constant::Keyword::ELSE,            Token::ELSE}
};

const std::unordered_set<std::string> TokenUtils::_types
{
	Constant::CoreType::Complex::ARRAY,
	Constant::CoreType::Number::DOUBLE,
	Constant::CoreType::Number::FLOAT,
	Constant::CoreType::Number::INTEGER,
	Constant::CoreType::Complex::STRING,
	Constant::CoreType::VOID
};

const std::unordered_set<std::string> TokenUtils::_delimitersToSkip
{
	Constant::Separator::SPACE,
	Constant::Separator::TAB,
	Constant::Separator::END_OF_LINE_LF,
	Constant::Separator::END_OF_LINE_CR,
	Constant::Separator::END_OF_LINE_CRLF,
	Constant::Comment::LINE,
	Constant::Comment::BLOCK_BEGINNING
};

#endif //PROJECT_TOKENUTILS_H
