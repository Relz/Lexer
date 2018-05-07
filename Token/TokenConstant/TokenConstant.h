#ifndef TOKEN_CONSTANT_H
#define TOKEN_CONSTANT_H

#include "../Parenthesis/Parenthesis.h"
#include <regex>
#include <string>
#include <vector>

class TokenConstant
{
public:
	class Comment
	{
	public:
		static std::wstring const BLOCK_BEGINNING;
		static std::wstring const BLOCK_ENDING;
		static std::wstring const LINE;
	};

	class Operator
	{
	public:
		class Arithmetic
		{
		public:
			static std::wstring const DIVISION;
			static std::wstring const MINUS;
			static wchar_t const MINUS_CHARACTER;
			static std::wstring const MULTIPLY;
			static std::wstring const PLUS;
			static wchar_t const PLUS_CHARACTER;
		};

		class Assignment
		{
		public:
			static std::wstring const ASSIGNMENT;
			static std::wstring const DIVISION_ASSIGNMENT;
			static std::wstring const MINUS_ASSIGNMENT;
			static std::wstring const MULTIPLY_ASSIGNMENT;
			static std::wstring const PLUS_ASSIGNMENT;
		};

		class Comparison
		{
		public:
			static std::wstring const EQUIVALENCE;
			static std::wstring const NOT_EQUIVALENCE;
			static std::wstring const MORE_OR_EQUIVALENCE;
			static std::wstring const LESS_OR_EQUIVALENCE;
			static std::wstring const MORE;
			static std::wstring const LESS;
		};
	};

	class Keyword
	{
	public:
		static std::wstring const CLASS;
		static std::wstring const CONSTRUCTOR;
		static std::wstring const DO;
		static std::wstring const EXTENDS;
		static std::wstring const FOR;
		static std::wstring const GET;
		static std::wstring const IMPLEMENTS;
		static std::wstring const NOT_INITIALIZED;
		static std::wstring const PRIVATE;
		static std::wstring const PUBLIC;
		static std::wstring const RETURN;
		static std::wstring const SET;
		static std::wstring const WHILE;
		static std::wstring const IF;
		static std::wstring const ELSE;
	};

	class CoreType
	{
	public:
		class Number
		{
		public:
			static std::wstring const DOUBLE;
			static std::wstring const FLOAT;
			static std::wstring const INTEGER;
		};

		class Complex
		{
		public:
			static std::wstring const ARRAY;
			static std::wstring const STRING;
		};

		static std::wstring const VOID;
	};

	class Separator
	{
	public:
		static std::wstring const DOT;
		static wchar_t const DOT_CHARACTER;
		static std::wstring const COLON;
		static std::wstring const COMMA;
		static std::wstring const SEMICOLON;
		static wchar_t const EXPONENT_CHARACTER;
		static std::wstring const SPACE;
		static std::wstring const TAB;
		static std::wstring const END_OF_LINE_LF;
		static std::wstring const END_OF_LINE_CR;
		static wchar_t const UNDERSCORE_CHARACTER;
	};

	class Parentheses
	{
	public:
		static Parenthesis const CURLY_BRACKET;
		static Parenthesis const ROUND_BRACKET;
		static Parenthesis const SQUARE_BRACKET;
		static wchar_t const QUOTE_CHARACTER;
		static std::wstring const QUOTE_STRING;
		static wchar_t const DOUBLE_QUOTE_CHARACTER;
		static std::wstring const DOUBLE_QUOTE_STRING;
	};

	class Name
	{
	public:
		static std::wstring const UNKNOWN;

		class Operator
		{
		public:
			class Arithmetic
			{
			public:
				static std::wstring const DIVISION;
				static std::wstring const MINUS;
				static std::wstring const MULTIPLY;
				static std::wstring const PLUS;
			};

			class Assignment
			{
			public:
				static std::wstring const ASSIGNMENT;
				static std::wstring const DIVISION_ASSIGNMENT;
				static std::wstring const MINUS_ASSIGNMENT;
				static std::wstring const MULTIPLY_ASSIGNMENT;
				static std::wstring const PLUS_ASSIGNMENT;
			};

			class Comparison
			{
			public:
				static std::wstring const EQUIVALENCE;
				static std::wstring const NOT_EQUIVALENCE;
				static std::wstring const MORE_OR_EQUIVALENCE;
				static std::wstring const LESS_OR_EQUIVALENCE;
				static std::wstring const MORE;
				static std::wstring const LESS;
			};
		};

		class Keyword
		{
		public:
			static std::wstring const CLASS;
			static std::wstring const CONSTRUCTOR;
			static std::wstring const DO;
			static std::wstring const EXTENDS;
			static std::wstring const FOR;
			static std::wstring const GET;
			static std::wstring const IMPLEMENTS;
			static std::wstring const NOT_INITIALIZED;
			static std::wstring const PRIVATE;
			static std::wstring const PUBLIC;
			static std::wstring const RETURN;
			static std::wstring const SET;
			static std::wstring const WHILE;
			static std::wstring const IF;
			static std::wstring const ELSE;
		};

		static std::wstring const INTEGER;
		static std::wstring const FLOAT;
		static std::wstring const EXPONENTIAL;

		class Separator
		{
		public:
			static std::wstring const DOT;
			static std::wstring const COLON;
			static std::wstring const COMMA;
			static std::wstring const SEMICOLON;
		};

		class Parentheses
		{
		public:
			static std::wstring const CURLY_BRACKET_LEFT;
			static std::wstring const CURLY_BRACKET_RIGHT;
			static std::wstring const ROUND_BRACKET_LEFT;
			static std::wstring const ROUND_BRACKET_RIGHT;
			static std::wstring const SQUARE_BRACKET_LEFT;
			static std::wstring const SQUARE_BRACKET_RIGHT;
		};

		static std::wstring const TYPE;
		static std::wstring const IDENTIFIER;
		static std::wstring const STRING_LITERAL;
		static std::wstring const CHARACTER_LITERAL;
		static std::wstring const LINE_COMMENT;
		static std::wstring const BLOCK_COMMENT;
	};

	class Regex
	{
	public:
		static std::wregex const IDENTIFIER;
	};
};

#endif
