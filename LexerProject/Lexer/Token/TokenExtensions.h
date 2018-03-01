#ifndef PROJECT_TOKENEXTENSIONS_H
#define PROJECT_TOKENEXTENSIONS_H

#include <string>
#include <unordered_set>
#include <unordered_map>
#include "Token.h"
#include "Constant/Constant.h"

class TokenExtensions
{
public:
	static bool TryToGetDelimiterToken(std::string const& str, Token & token)
	{
		if (STRING_TO_DELIMITER_TOKEN.find(str) == STRING_TO_DELIMITER_TOKEN.end())
		{
			return false;
		}
		token = STRING_TO_DELIMITER_TOKEN.at(str);
		return true;
	}

	static bool TryToGetKeywordToken(std::string const& str, Token & token)
	{
		if (STRING_TO_KEYWORD_TOKEN.find(str) == STRING_TO_KEYWORD_TOKEN.end())
		{
			return false;
		}
		token = STRING_TO_KEYWORD_TOKEN.at(str);
		return true;
	}

	static bool TryToGetTypeToken(std::string const& str, Token & token)
	{
		if (TYPES.find(str) == TYPES.end())
		{
			return false;
		}
		token = Token::TYPE;
		return true;
	}

	static std::string ToString(Token token)
	{
		return TOKEN_TO_NAME.find(token) == TOKEN_TO_NAME.end() ? "" : TOKEN_TO_NAME.at(token);
	}

private:
	static std::unordered_map<std::string, Token> const STRING_TO_DELIMITER_TOKEN;
	static std::unordered_map<std::string, Token> const STRING_TO_KEYWORD_TOKEN;
	static std::unordered_set<std::string> const TYPES;
	static std::unordered_map<Token, std::string> const TOKEN_TO_NAME;

};

std::unordered_map<std::string, Token> const TokenExtensions::STRING_TO_DELIMITER_TOKEN
{
	{Constant::Operator::Arithmetic::DIVISION, Token::DIVISION},
	{Constant::Operator::Arithmetic::MINUS, Token::MINUS},
	{Constant::Operator::Arithmetic::MULTIPLY, Token::MULTIPLY},
	{Constant::Operator::Arithmetic::PLUS, Token::PLUS},

	{Constant::Operator::Assignment::ASSIGNMENT, Token::ASSIGNMENT},
	{Constant::Operator::Assignment::PLUS_ASSIGNMENT, Token::PLUS_ASSIGNMENT},
	{Constant::Operator::Assignment::MINUS_ASSIGNMENT, Token::MINUS_ASSIGNMENT},
	{Constant::Operator::Assignment::MULTIPLY_ASSIGNMENT, Token::MULTIPLY_ASSIGNMENT},
	{Constant::Operator::Assignment::DIVISION_ASSIGNMENT, Token::DIVISION_ASSIGNMENT},

	{Constant::Operator::Comparison::EQUIVALENCE, Token::EQUIVALENCE},
	{Constant::Operator::Comparison::NOT_EQUIVALENCE, Token::NOT_EQUIVALENCE},
	{Constant::Operator::Comparison::MORE_OR_EQUIVALENCE, Token::MORE_OR_EQUIVALENCE},
	{Constant::Operator::Comparison::LESS_OR_EQUIVALENCE, Token::LESS_OR_EQUIVALENCE},
	{Constant::Operator::Comparison::MORE, Token::MORE},
	{Constant::Operator::Comparison::LESS, Token::LESS},

	{Constant::Separator::COLON, Token::COLON},
	{Constant::Separator::COMMA, Token::COMMA},
	{Constant::Separator::DOT, Token::DOT},
	{Constant::Separator::SEMICOLON, Token::SEMICOLON},

	{Constant::Parentheses::CURLY_BRACKET.LEFT, Token::LEFT_CURLY_BRACKET},
	{Constant::Parentheses::CURLY_BRACKET.RIGHT, Token::RIGHT_CURLY_BRACKET},
	{Constant::Parentheses::ROUND_BRACKET.LEFT, Token::LEFT_ROUND_BRACKET},
	{Constant::Parentheses::ROUND_BRACKET.RIGHT, Token::RIGHT_ROUND_BRACKET},
	{Constant::Parentheses::SQUARE_BRACKET.LEFT, Token::LEFT_SQUARE_BRACKET},
	{Constant::Parentheses::SQUARE_BRACKET.RIGHT, Token::RIGHT_SQUARE_BRACKET}
};

std::unordered_map<std::string, Token> const TokenExtensions::STRING_TO_KEYWORD_TOKEN
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

std::unordered_set<std::string> const TokenExtensions::TYPES
{
	Constant::CoreType::Complex::ARRAY,
	Constant::CoreType::Number::DOUBLE,
	Constant::CoreType::Number::FLOAT,
	Constant::CoreType::Number::INTEGER,
	Constant::CoreType::Complex::STRING,
	Constant::CoreType::VOID
};

std::unordered_map<Token, std::string> const TokenExtensions::TOKEN_TO_NAME
{
	{Token::DIVISION, Constant::Name::Operator::Arithmetic::DIVISION},
	{Token::MINUS, Constant::Name::Operator::Arithmetic::MINUS},
	{Token::MULTIPLY, Constant::Name::Operator::Arithmetic::MULTIPLY},
	{Token::PLUS, Constant::Name::Operator::Arithmetic::PLUS},

	{Token::PLUS_ASSIGNMENT, Constant::Name::Operator::Assignment::PLUS_ASSIGNMENT},
	{Token::MULTIPLY_ASSIGNMENT, Constant::Name::Operator::Assignment::MULTIPLY_ASSIGNMENT},
	{Token::MINUS_ASSIGNMENT, Constant::Name::Operator::Assignment::MINUS_ASSIGNMENT},
	{Token::DIVISION_ASSIGNMENT, Constant::Name::Operator::Assignment::DIVISION_ASSIGNMENT},
	{Token::ASSIGNMENT, Constant::Name::Operator::Assignment::ASSIGNMENT},

	{Token::EQUIVALENCE, Constant::Name::Operator::Comparison::EQUIVALENCE},
	{Token::NOT_EQUIVALENCE, Constant::Name::Operator::Comparison::NOT_EQUIVALENCE},
	{Token::MORE_OR_EQUIVALENCE, Constant::Name::Operator::Comparison::MORE_OR_EQUIVALENCE},
	{Token::LESS_OR_EQUIVALENCE, Constant::Name::Operator::Comparison::LESS_OR_EQUIVALENCE},
	{Token::MORE, Constant::Name::Operator::Comparison::MORE},
	{Token::LESS, Constant::Name::Operator::Comparison::LESS},

	{Token::CLASS, Constant::Name::Keyword::CLASS},
	{Token::CONSTRUCTOR, Constant::Name::Keyword::CONSTRUCTOR},
	{Token::DO, Constant::Name::Keyword::DO},
	{Token::EXTENDS, Constant::Name::Keyword::EXTENDS},
	{Token::FOR, Constant::Name::Keyword::FOR},
	{Token::WHILE, Constant::Name::Keyword::WHILE},
	{Token::GET, Constant::Name::Keyword::GET},
	{Token::IMPLEMENTS, Constant::Name::Keyword::IMPLEMENTS},
	{Token::NOT_INITIALIZED, Constant::Name::Keyword::NOT_INITIALIZED},
	{Token::PRIVATE, Constant::Name::Keyword::PRIVATE},
	{Token::PUBLIC, Constant::Name::Keyword::PUBLIC},
	{Token::RETURN, Constant::Name::Keyword::RETURN},
	{Token::SET, Constant::Name::Keyword::SET},
	{Token::IF, Constant::Name::Keyword::IF},
	{Token::ELSE, Constant::Name::Keyword::ELSE},

	{Token::INTEGER, Constant::Name::INTEGER},
	{Token::FLOAT, Constant::Name::FLOAT},
	{Token::EXPONENTIAL, Constant::Name::EXPONENTIAL},

	{Token::DOT, Constant::Name::Separator::DOT},
	{Token::COLON, Constant::Name::Separator::COLON},
	{Token::COMMA, Constant::Name::Separator::COMMA},
	{Token::SEMICOLON, Constant::Name::Separator::SEMICOLON},

	{Token::LEFT_CURLY_BRACKET, Constant::Name::Parentheses::CURLY_BRACKET_LEFT},
	{Token::RIGHT_CURLY_BRACKET, Constant::Name::Parentheses::CURLY_BRACKET_RIGHT},
	{Token::LEFT_ROUND_BRACKET, Constant::Name::Parentheses::ROUND_BRACKET_LEFT},
	{Token::RIGHT_ROUND_BRACKET, Constant::Name::Parentheses::ROUND_BRACKET_RIGHT},
	{Token::LEFT_SQUARE_BRACKET, Constant::Name::Parentheses::SQUARE_BRACKET_LEFT},
	{Token::RIGHT_SQUARE_BRACKET, Constant::Name::Parentheses::SQUARE_BRACKET_RIGHT},

	{Token::TYPE, Constant::Name::TYPE},
	{Token::IDENTIFIER, Constant::Name::IDENTIFIER},
	{Token::STRING_LITERAL, Constant::Name::STRING_LITERAL},
	{Token::CHARACTER_LITERAL, Constant::Name::CHARACTER_LITERAL},
	{Token::UNKNOWN, Constant::Name::UNKNOWN}
};

#endif //PROJECT_TOKENEXTENSIONS_H
