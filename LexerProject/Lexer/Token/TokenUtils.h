#ifndef TOKEN_TOKENUTILS_H
#define TOKEN_TOKENUTILS_H

#include <string>
#include <stdexcept>
#include <unordered_map>
#include "Constant/Constant.h"
#include "Rule.h"
#include "Token.h"
#include "TokenInformation.h"

namespace
{
	class TokenUtils
	{
	public:
		static bool DetermineScannedStringToken(std::string const& scannedString, Token & token)
		{
			if (!scannedString.empty())
			{
				if (Rule::IsIdentifier(scannedString))
				{
					if (TryAddTokenAt(STRING_TO_KEYWORD_TOKEN, scannedString, token)
						|| TryAddTypeAt(scannedString, token))
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

		static bool DetermineDelimiterToken(std::string const & delimiterString, Token & token)
		{
			token = Token::UNKNOWN;
			return DELIMITERS_TO_SKIP.find(delimiterString) == DELIMITERS_TO_SKIP.end()
					&&
						(
							TryToAddLiteralToken(delimiterString, token)
								|| TryAddTokenAt(STRING_TO_COMPARISON_OPERATOR_TOKEN, delimiterString, token)
								|| TryAddTokenAt(STRING_TO_ASSIGNMENT_OPERATOR_TOKEN, delimiterString, token)
								|| TryAddTokenAt(STRING_TO_ARITHMETIC_OPERATOR_TOKEN, delimiterString, token)
								|| TryAddTokenAt(STRING_TO_SEPARATOR_TOKEN, delimiterString, token)
								|| TryAddTokenAt(STRING_TO_PARENTHESIS_TOKEN, delimiterString, token)
						);
		}

	private:
		static bool TryAddTokenAt(
			std::unordered_map<std::string, Token> const& unorderedMap,
			std::string const& searchStr,
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

		static bool TryAddTypeAt(std::string const& searchStr, Token & token)
		{
			if (TYPES.find(searchStr) != TYPES.end())
			{
				token = Token::TYPE;
				return true;
			}
			else
			{
				return false;
			}
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

		static bool DetermineNumberToken(std::string const& scannedString, Token & token)
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
					numberSystem = stoul(goodString);
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

		static std::unordered_map<std::string, Token> const STRING_TO_ARITHMETIC_OPERATOR_TOKEN;
		static std::unordered_map<std::string, Token> const STRING_TO_ASSIGNMENT_OPERATOR_TOKEN;
		static std::unordered_map<std::string, Token> const STRING_TO_COMPARISON_OPERATOR_TOKEN;
		static std::unordered_map<std::string, Token> const STRING_TO_SEPARATOR_TOKEN;
		static std::unordered_map<std::string, Token> const STRING_TO_PARENTHESIS_TOKEN;
		static std::unordered_map<std::string, Token> const STRING_TO_KEYWORD_TOKEN;
		static std::unordered_set<std::string> const TYPES;
		static std::unordered_set<std::string> const DELIMITERS_TO_SKIP;
	};
}

std::unordered_map<std::string, Token> const TokenUtils::STRING_TO_ARITHMETIC_OPERATOR_TOKEN
{
	{Constant::Operator::Arithmetic::DIVISION, Token::DIVISION},
	{Constant::Operator::Arithmetic::MINUS, Token::MINUS},
	{Constant::Operator::Arithmetic::MULTIPLY, Token::MULTIPLY},
	{Constant::Operator::Arithmetic::PLUS, Token::PLUS}
};

std::unordered_map<std::string, Token> const TokenUtils::STRING_TO_ASSIGNMENT_OPERATOR_TOKEN
{
	{Constant::Operator::Assignment::ASSIGNMENT, Token::ASSIGNMENT},
	{Constant::Operator::Assignment::PLUS_ASSIGNMENT, Token::PLUS_ASSIGNMENT},
	{Constant::Operator::Assignment::MINUS_ASSIGNMENT, Token::MINUS_ASSIGNMENT},
	{Constant::Operator::Assignment::MULTIPLY_ASSIGNMENT, Token::MULTIPLY_ASSIGNMENT},
	{Constant::Operator::Assignment::DIVISION_ASSIGNMENT, Token::DIVISION_ASSIGNMENT}
};

std::unordered_map<std::string, Token> const TokenUtils::STRING_TO_COMPARISON_OPERATOR_TOKEN
{
	{Constant::Operator::Comparison::EQUIVALENCE, Token::EQUIVALENCE},
	{Constant::Operator::Comparison::NOT_EQUIVALENCE, Token::NOT_EQUIVALENCE},
	{Constant::Operator::Comparison::MORE_OR_EQUIVALENCE, Token::MORE_OR_EQUIVALENCE},
	{Constant::Operator::Comparison::LESS_OR_EQUIVALENCE, Token::LESS_OR_EQUIVALENCE},
	{Constant::Operator::Comparison::MORE, Token::MORE},
	{Constant::Operator::Comparison::LESS, Token::LESS}
};

std::unordered_map<std::string, Token> const TokenUtils::STRING_TO_SEPARATOR_TOKEN
{
	{Constant::Separator::COLON, Token::COLON},
	{Constant::Separator::COMMA, Token::COMMA},
	{Constant::Separator::DOT, Token::DOT},
	{Constant::Separator::SEMICOLON, Token::SEMICOLON}
};

std::unordered_map<std::string, Token> const TokenUtils::STRING_TO_PARENTHESIS_TOKEN
{
	{Constant::Parentheses::CURLY_BRACKET.LEFT, Token::LEFT_CURLY_BRACKET},
	{Constant::Parentheses::CURLY_BRACKET.RIGHT, Token::RIGHT_CURLY_BRACKET},
	{Constant::Parentheses::ROUND_BRACKET.LEFT, Token::LEFT_ROUND_BRACKET},
	{Constant::Parentheses::ROUND_BRACKET.RIGHT, Token::RIGHT_ROUND_BRACKET},
	{Constant::Parentheses::SQUARE_BRACKET.LEFT, Token::LEFT_SQUARE_BRACKET},
	{Constant::Parentheses::SQUARE_BRACKET.RIGHT, Token::RIGHT_SQUARE_BRACKET}
};

std::unordered_map<std::string, Token> const TokenUtils::STRING_TO_KEYWORD_TOKEN
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

std::unordered_set<std::string> const TokenUtils::TYPES
{
	Constant::CoreType::Complex::ARRAY,
	Constant::CoreType::Number::DOUBLE,
	Constant::CoreType::Number::FLOAT,
	Constant::CoreType::Number::INTEGER,
	Constant::CoreType::Complex::STRING,
	Constant::CoreType::VOID
};

std::unordered_set<std::string> const TokenUtils::DELIMITERS_TO_SKIP
{
	Constant::Separator::SPACE,
	Constant::Separator::TAB,
	Constant::Separator::END_OF_LINE_LF,
	Constant::Separator::END_OF_LINE_CR,
	Constant::Comment::LINE,
	Constant::Comment::BLOCK_BEGINNING
};

#endif //PROJECT_TOKENUTILS_H
