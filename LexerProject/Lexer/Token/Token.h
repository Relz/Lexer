#ifndef TOKEN_TOKEN_H
#define TOKEN_TOKEN_H

#include "Constant/Constant.h"

enum Token
{
	// Arithmetic operators
	PLUS,
	MINUS,
	MULTIPLY,
	DIVISION,

	// Assignment operators
	ASSIGNMENT,
	PLUS_ASSIGNMENT,
	MINUS_ASSIGNMENT,
	MULTIPLY_ASSIGNMENT,
	DIVISION_ASSIGNMENT,

	// Comparison operators
	EQUIVALENCE,
	NOT_EQUIVALENCE,
	MORE_OR_EQUIVALENCE,
	LESS_OR_EQUIVALENCE,
	MORE,
	LESS,

	// Keywords
	CLASS,
	EXTENDS,
	IMPLEMENTS,
	CONSTRUCTOR,
	NOT_INITIALIZED,
	PRIVATE,
	PUBLIC,
	GET,
	SET,
	FOR,
	WHILE,
	DO,
	RETURN,
	IF,
	ELSE,

	// Numbers
	INTEGER,
	FLOAT,
	EXPONENTIAL,

	// Separator
	COLON,
	COMMA,
	DOT,
	SEMICOLON,

	// Parentheses
	LEFT_SQUARE_BRACKET,
	RIGHT_SQUARE_BRACKET,

	LEFT_ROUND_BRACKET,
	RIGHT_ROUND_BRACKET,

	LEFT_CURLY_BRACKET,
	RIGHT_CURLY_BRACKET,

	LEFT_ANGLE_BRACKET,
	RIGHT_ANGLE_BRACKET,

	// Other
	TYPE,
	IDENTIFIER,
	STRING_LITERAL,
	CHARACTER_LITERAL,
	UNKNOWN
};

namespace TokenExtensions
{
	static const std::unordered_map<Token, std::string> _tokenToString
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

					{Token::LEFT_ANGLE_BRACKET, Constant::Name::Parentheses::ANGLE_BRACKET_LEFT},
					{Token::RIGHT_ANGLE_BRACKET, Constant::Name::Parentheses::ANGLE_BRACKET_RIGHT},
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

	static std::string ToString(Token token)
	{
		try
		{
			return _tokenToString.at(token);
		}
		catch (std::out_of_range &)
		{
			return "";
		}
	}
}

#endif //PROJECT_TOKEN_H
