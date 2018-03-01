#ifndef TOKEN_CONSTANT_H
#define TOKEN_CONSTANT_H

#include <string>
#include <vector>
#include <regex>
#include "Parenthesis.h"

namespace Constant
{
	namespace Comment
	{
		static std::string const BLOCK_BEGINNING = "/*";
		static std::string const BLOCK_ENDING = "*/";
		static std::string const LINE = "//";
	}

	namespace Operator
	{
		namespace Arithmetic
		{
			static std::string const DIVISION = "/";
			static std::string const MINUS = "-";
			static char const MINUS_CHARACTER = '-';
			static std::string const MULTIPLY = "*";
			static std::string const PLUS = "+";
			static char const PLUS_CHARACTER = '+';
		};

		namespace Assignment
		{
			static std::string const ASSIGNMENT = "=";
			static std::string const DIVISION_ASSIGNMENT = "/=";
			static std::string const MINUS_ASSIGNMENT = "-=";
			static std::string const MULTIPLY_ASSIGNMENT = "*=";
			static std::string const PLUS_ASSIGNMENT = "+=";
		}

		namespace Comparison
		{
			static std::string const EQUIVALENCE = "==";
			static std::string const NOT_EQUIVALENCE = "!=";
			static std::string const MORE_OR_EQUIVALENCE = ">=";
			static std::string const LESS_OR_EQUIVALENCE = "<=";
			static std::string const MORE = ">";
			static std::string const LESS = "<";
		}
	}

	namespace Keyword
	{
		static std::string const CLASS = "class";
		static std::string const CONSTRUCTOR = "Constructor";
		static std::string const DO = "do";
		static std::string const EXTENDS = "extends";
		static std::string const FOR = "for";
		static std::string const GET = "get";
		static std::string const IMPLEMENTS = "implements";
		static std::string const NOT_INITIALIZED = "NULL";
		static std::string const PRIVATE = "private";
		static std::string const PUBLIC = "public";
		static std::string const RETURN = "return";
		static std::string const SET = "set";
		static std::string const WHILE = "while";
		static std::string const IF = "if";
		static std::string const ELSE = "else";
	}

	namespace CoreType
	{
		namespace Number
		{
			static std::string const DOUBLE = "Double";
			static std::string const FLOAT = "Float";
			static std::string const INTEGER = "Integer";
		};

		namespace Complex
		{
			static std::string const ARRAY = "Array";
			static std::string const STRING = "String";
		}

		static std::string const VOID = "Void";
	}

	namespace Separator
	{
		static std::string const DOT = ".";
		static char const DOT_CHARACTER = '.';
		static std::string const COLON = ":";
		static std::string const COMMA = ",";
		static std::string const SEMICOLON = ";";
		static char const EXPONENT_CHARACTER = 'E';
		static std::string const SPACE = " ";
		static std::string const TAB = "\t";
		static std::string const END_OF_LINE_LF = "\n";
		static std::string const END_OF_LINE_CR = "\r";
		static char const UNDERSCORE_CHARACTER = '_';
	}

	namespace Parentheses
	{
		static Parenthesis const CURLY_BRACKET = {"{", "}"};
		static Parenthesis const ROUND_BRACKET = {"(", ")"};
		static Parenthesis const SQUARE_BRACKET = {"[", "]"};
		static char const QUOTE_CHARACTER = '\'';
		static std::string const QUOTE_STRING = "'";
		static char const DOUBLE_QUOTE_CHARACTER = '"';
		static std::string const DOUBLE_QUOTE_STRING = "\"";
	}

	namespace Name
	{
		namespace Operator
		{
			namespace Arithmetic
			{
				static std::string const DIVISION = "Division";
				static std::string const MINUS = "Minus";
				static std::string const MULTIPLY = "Multiply";
				static std::string const PLUS = "Plus";
			}

			namespace Assignment
			{
				static std::string const ASSIGNMENT = "Assignment";
				static std::string const DIVISION_ASSIGNMENT = "Division assignment";
				static std::string const MINUS_ASSIGNMENT = "Minus assignment";
				static std::string const MULTIPLY_ASSIGNMENT = "Multiply assignment";
				static std::string const PLUS_ASSIGNMENT = "Plus assignment";
			}

			namespace Comparison
			{
				static std::string const EQUIVALENCE = "Equivalence";
				static std::string const NOT_EQUIVALENCE = "Not equivalence";
				static std::string const MORE_OR_EQUIVALENCE = "More or equal";
				static std::string const LESS_OR_EQUIVALENCE = "Less or equal";
				static std::string const MORE = "More";
				static std::string const LESS = "Less";
			}
		}

		namespace Keyword
		{
			static std::string const CLASS = "Class keyword";
			static std::string const CONSTRUCTOR = "Constructor keyword";
			static std::string const DO = "Do keyword";
			static std::string const EXTENDS = "Extends keyword";
			static std::string const FOR = "For keyword";
			static std::string const GET = "Get keyword";
			static std::string const IMPLEMENTS = "Implements keyword";
			static std::string const NOT_INITIALIZED = "NULL keyword";
			static std::string const PRIVATE = "Private keyword";
			static std::string const PUBLIC = "Public keyword";
			static std::string const RETURN = "Return keyword";
			static std::string const SET = "Set keyword";
			static std::string const WHILE = "While keyword";
			static std::string const IF = "If keyword";
			static std::string const ELSE = "Else keyword";
		}

		static std::string const INTEGER = "Integer";
		static std::string const FLOAT = "Float";
		static std::string const EXPONENTIAL = "Exponential";

		namespace Separator
		{
			static std::string const DOT = "Dot";
			static std::string const COLON = "Colon";
			static std::string const COMMA = "Comma";
			static std::string const SEMICOLON = "Semicolon";
		}

		namespace Parentheses
		{
			static std::string const CURLY_BRACKET_LEFT = "Left curly bracket";
			static std::string const CURLY_BRACKET_RIGHT = "Right curly bracket";
			static std::string const ROUND_BRACKET_LEFT = "Left round bracket";
			static std::string const ROUND_BRACKET_RIGHT = "Right round bracket";
			static std::string const SQUARE_BRACKET_LEFT = "Left square bracket";
			static std::string const SQUARE_BRACKET_RIGHT = "Right square bracket";
		}

		static std::string const TYPE = "Type";
		static std::string const IDENTIFIER = "Identifier";
		static std::string const STRING_LITERAL = "String literal";
		static std::string const CHARACTER_LITERAL = "Character literal";
		static std::string const UNKNOWN = "Unknown";
	}

	namespace Regex
	{
		static std::regex const IDENTIFIER("[_a-zA-Z][_a-zA-Z0-9]*");
	}
}

#endif //TOKEN_CONSTANT_H
