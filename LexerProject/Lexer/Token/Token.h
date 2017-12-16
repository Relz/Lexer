#ifndef PROJECT_TOKEN_H
#define PROJECT_TOKEN_H

//enum Operator
//{
//	PLUS,
//	MINUS,
//	MULTIPLY,
//	DIVISION
//};
//
//enum Number
//{
//	INTEGER,
//	FLOAT,
//	DOUBLE
//};
//
//enum Type : Number
//{
//	STRING,
//	ARRAY
//};
//
//enum Keyword
//{
//	CLASS,
//	EXTENDS,
//	IMPLEMENTS,
//	CONSTRUCTOR,
//	NOT_INITIALIZED,
//	PRIVATE,
//	PUBLIC,
//	GET,
//	SET,
//	FOR,
//	WHILE,
//	DO,
//	RETURN
//};
//
//enum CoreLibrary
//{
//	CONSOLE
//};
//
//enum Separator
//{
//	DOT,
//	COMMA,
//	SEMICOLON,
//	COLON
//};
//
//enum Parentheses
//{
//	LEFT_SQUARE_BRACKET,
//	RIGHT_SQUARE_BRACKET,
//
//	LEFT_ROUND_BRACKET,
//	RIGHT_ROUND_BRACKET,
//
//	LEFT_CURLY_BRACKET,
//	RIGHT_CURLY_BRACKET,
//
//	LEFT_ANGLE_BRACKET,
//	RIGHT_ANGLE_BRACKET,
//};

enum Token
{
	// Operators
	PLUS,
	MINUS,
	MULTIPLY,
	DIVISION,

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

	// Core types
	// Numbers
	INTEGER,
	FLOAT,
	DOUBLE,

	// Complex
	STRING,
	ARRAY,

	// Core library
	CONSOLE,

	// Separator
	DOT,
	COMMA,
	SEMICOLON,
	COLON,

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
	IDENTIFIER,
	ASSIGNMENT,
	UNKNOWN
};

#endif //PROJECT_TOKEN_H
