#ifndef TOKEN_TOKENUTILS_H
#define TOKEN_TOKENUTILS_H

#include <string>
#include <stdexcept>
#include <unordered_map>
#include "Constant/Constant.h"
#include "Rule.h"
#include "Token.h"
#include "TokenInformation.h"

using namespace std;

namespace
{
	class TokenUtils
	{
	public:
		static void DetermineTokens(
			string const& scannedString,
			StreamPosition scannedStringPosition,
			string const& delimiter,
			StreamPosition delimiterPosition,
			Token delimiterToken,
			bool delimiterTokenDetermined,
			vector<TokenInformation> & tokenInfos
		)
		{
			bool skipDelimiterDetermining = (_delimitersToSkip.find(delimiter) != _delimitersToSkip.end());

			if (!scannedString.empty())
			{
				Token scannedStringToken;
				DetermineScannedStringToken(scannedString, scannedStringToken);
				tokenInfos.emplace_back(TokenInformation(scannedStringToken, scannedString, scannedStringPosition));
			}

			if (!skipDelimiterDetermining)
			{
				if (!delimiterTokenDetermined)
				{
					DetermineDelimiterToken(delimiter, delimiterToken);
				}
				tokenInfos.emplace_back(TokenInformation(delimiterToken, delimiter, delimiterPosition));
			}
		}

	private:
		static bool TryAddTokenAt(
			unordered_map<string, Token> const& unorderedMap,
			string const& searchStr,
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

		static bool TryAddTypeAt(string const& searchStr, Token & token)
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

		static bool DetermineScannedStringToken(string const& scannedString, Token & token)
		{
			if (!scannedString.empty())
			{
				if (Rule::IsIdentifier(scannedString))
				{
					if (
						TryAddTokenAt(STRING_TO_KEYWORD_TOKEN, scannedString, token)
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
			return false;
		}

		static bool DetermineDelimiterToken(string const& delimiter, Token & token)
		{
			token = Token::UNKNOWN;
			return TryAddTokenAt(_stringsToComparisonOperatorTokens, delimiter, token)
				|| TryAddTokenAt(_stringsToAssignmentOperatorTokens, delimiter, token)
				|| TryAddTokenAt(STRING_TO_ARITHMETIC_OPERATOR_TOKEN, delimiter, token)
				|| TryAddTokenAt(STRING_TO_SEPARATOR_TOKEN, delimiter, token)
				|| TryAddTokenAt(STRING_TO_PARENTHESIS_TOKEN, delimiter, token);
		}

		static bool DetermineNumberToken(string const& scannedString, Token & token)
		{
			if (scannedString.empty() || !Rule::IsDigit(scannedString.front()))
			{
				return false;
			}

			size_t failIndex;
			string goodString;
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
					numberSystem = stoul(goodString);
					if (numberSystem > Constant::Number::MAX_SYSTEM)
					{
						throw exception();
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

		static const unordered_map<string, Token> STRING_TO_ARITHMETIC_OPERATOR_TOKEN;
		static const unordered_map<string, Token> STRING_TO_ASSIGNMENT_OPERATOR_TOKEN;
		static const unordered_map<string, Token> STRING_TO_COMPARISON_OPERATOR_TOKEN;
		static const unordered_map<string, Token> STRING_TO_SEPARATOR_TOKEN;
		static const unordered_map<string, Token> STRING_TO_PARENTHESIS_TOKEN;
		static const unordered_map<string, Token> STRING_TO_KEYWORD_TOKEN;
		static const unordered_set<string> TYPES;
		static const unordered_set<string> _delimitersToSkip;
	};
}

const unordered_map<string, Token> TokenUtils::STRING_TO_ARITHMETIC_OPERATOR_TOKEN
{
	{Constant::Operator::Arithmetic::DIVISION, Token::DIVISION},
	{Constant::Operator::Arithmetic::MINUS, Token::MINUS},
	{Constant::Operator::Arithmetic::MULTIPLY, Token::MULTIPLY},
	{Constant::Operator::Arithmetic::PLUS, Token::PLUS}
};

const unordered_map<string, Token> TokenUtils::STRING_TO_ASSIGNMENT_OPERATOR_TOKEN
{
	{Constant::Operator::Assignment::ASSIGNMENT, Token::ASSIGNMENT},
	{Constant::Operator::Assignment::PLUS_ASSIGNMENT, Token::PLUS_ASSIGNMENT},
	{Constant::Operator::Assignment::MINUS_ASSIGNMENT, Token::MINUS_ASSIGNMENT},
	{Constant::Operator::Assignment::MULTIPLY_ASSIGNMENT, Token::MULTIPLY_ASSIGNMENT},
	{Constant::Operator::Assignment::DIVISION_ASSIGNMENT, Token::DIVISION_ASSIGNMENT}
};

const unordered_map<string, Token> TokenUtils::STRING_TO_COMPARISON_OPERATOR_TOKEN
{
	{Constant::Operator::Comparison::EQUIVALENCE, Token::EQUIVALENCE},
	{Constant::Operator::Comparison::NOT_EQUIVALENCE, Token::NOT_EQUIVALENCE},
	{Constant::Operator::Comparison::MORE_OR_EQUIVALENCE, Token::MORE_OR_EQUIVALENCE},
	{Constant::Operator::Comparison::LESS_OR_EQUIVALENCE, Token::LESS_OR_EQUIVALENCE},
	{Constant::Operator::Comparison::MORE, Token::MORE},
	{Constant::Operator::Comparison::LESS, Token::LESS}
};

const unordered_map<string, Token> TokenUtils::STRING_TO_SEPARATOR_TOKEN
{
	{Constant::Separator::COLON, Token::COLON},
	{Constant::Separator::COMMA, Token::COMMA},
	{Constant::Separator::DOT, Token::DOT},
	{Constant::Separator::SEMICOLON, Token::SEMICOLON}
};

const unordered_map<string, Token> TokenUtils::STRING_TO_PARENTHESIS_TOKEN
{
	{Constant::Parentheses::ANGLE_BRACKET.LEFT, Token::LEFT_ANGLE_BRACKET},
	{Constant::Parentheses::ANGLE_BRACKET.RIGHT, Token::RIGHT_ANGLE_BRACKET},
	{Constant::Parentheses::CURLY_BRACKET.LEFT, Token::LEFT_CURLY_BRACKET},
	{Constant::Parentheses::CURLY_BRACKET.RIGHT, Token::RIGHT_CURLY_BRACKET},
	{Constant::Parentheses::ROUND_BRACKET.LEFT, Token::LEFT_ROUND_BRACKET},
	{Constant::Parentheses::ROUND_BRACKET.RIGHT, Token::RIGHT_ROUND_BRACKET},
	{Constant::Parentheses::SQUARE_BRACKET.LEFT, Token::LEFT_SQUARE_BRACKET},
	{Constant::Parentheses::SQUARE_BRACKET.RIGHT, Token::RIGHT_SQUARE_BRACKET}
};

const unordered_map<string, Token> TokenUtils::STRING_TO_KEYWORD_TOKEN
{
	{Constant::Keyword::CLASS, Token::CLASS},
	{Constant::Keyword::CONSTRUCTOR, Token::CONSTRUCTOR},
	{Constant::Keyword::DO, Token::DO},
	{Constant::Keyword::EXTENDS, Token::EXTENDS},
	{Constant::Keyword::FOR, Token::FOR},
	{Constant::Keyword::GET, Token::GET},
	{Constant::Keyword::IMPLEMENTS, Token::IMPLEMENTS},
	{Constant::Keyword::NOT_INITIALIZED, Token::NOT_INITIALIZED},
	{Constant::Keyword::PRIVATE, Token::PRIVATE},
	{Constant::Keyword::PUBLIC, Token::PUBLIC},
	{Constant::Keyword::SET, Token::SET},
	{Constant::Keyword::RETURN, Token::RETURN},
	{Constant::Keyword::WHILE, Token::WHILE},
	{Constant::Keyword::IF, Token::IF},
	{Constant::Keyword::ELSE, Token::ELSE}
};

const unordered_set<string> TokenUtils::_types
{
	Constant::CoreType::Complex::ARRAY,
	Constant::CoreType::Number::DOUBLE,
	Constant::CoreType::Number::FLOAT,
	Constant::CoreType::Number::INTEGER,
	Constant::CoreType::Complex::STRING,
	Constant::CoreType::VOID
};

const unordered_set<string> TokenUtils::_delimitersToSkip
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
