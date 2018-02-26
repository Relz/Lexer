#ifndef TOKEN_CONSTANT_H
#define TOKEN_CONSTANT_H

#include <string>
#include <vector>
#include "Parenthesis.h"

namespace Constant
{
	namespace Comment
	{
		std::string const BLOCK_BEGINNING = "/*";
		std::string const BLOCK_ENDING = "*/";
		std::string const LINE = "//";
	}

	namespace Operator
	{
		namespace Arithmetic
		{
			std::string const DIVISION = "/";
			std::string const MINUS = "-";
			char const MINUS_CHARACTER = '-';
			std::string const MULTIPLY = "*";
			std::string const PLUS = "+";
			char const PLUS_CHARACTER = '+';
		};

		namespace Assignment
		{
			std::string const ASSIGNMENT = "=";
			std::string const DIVISION_ASSIGNMENT = "/=";
			std::string const MINUS_ASSIGNMENT = "-=";
			std::string const MULTIPLY_ASSIGNMENT = "*=";
			std::string const PLUS_ASSIGNMENT = "+=";
		}

		namespace Comparison
		{
			std::string const EQUIVALENCE = "==";
			std::string const NOT_EQUIVALENCE = "!=";
			std::string const MORE_OR_EQUIVALENCE = ">=";
			std::string const LESS_OR_EQUIVALENCE = "<=";
			std::string const MORE = ">";
			std::string const LESS = "<";
		}
	}

	namespace Keyword
	{
		std::string const CLASS = "class";
		std::string const CONSTRUCTOR = "Constructor";
		std::string const DO = "do";
		std::string const EXTENDS = "extends";
		std::string const FOR = "for";
		std::string const GET = "get";
		std::string const IMPLEMENTS = "implements";
		std::string const NOT_INITIALIZED = "NULL";
		std::string const PRIVATE = "private";
		std::string const PUBLIC = "public";
		std::string const RETURN = "return";
		std::string const SET = "set";
		std::string const WHILE = "while";
		std::string const IF = "if";
		std::string const ELSE = "else";
	}

	namespace CoreType
	{
		namespace Number
		{
			std::string const DOUBLE = "Double";
			std::string const FLOAT = "Float";
			std::string const INTEGER = "Integer";
		};

		namespace Complex
		{
			std::string const ARRAY = "Array";
			std::string const STRING = "String";
		}

		std::string const VOID = "Void";
	}

	namespace Separator
	{
		std::string const DOT = ".";
		char const DOT_CHARACTER = '.';
		std::string const COLON = ":";
		std::string const COMMA = ",";
		std::string const SEMICOLON = ";";
		std::string const EXPONENT = "E";
		char const EXPONENT_CHARACTER = 'E';
		std::string const SPACE = " ";
		std::string const TAB = "\t";
		std::string const END_OF_LINE_LF = "\n";
		std::string const END_OF_LINE_CR = "\r";
		std::string const UNDERSCORE = "_";
		char const UNDERSCORE_CHARACTER = '_';
	}

	namespace Parentheses
	{
		Parenthesis const CURLY_BRACKET = {"{", "}"};
		Parenthesis const ROUND_BRACKET = {"(", ")"};
		Parenthesis const SQUARE_BRACKET = {"[", "]"};
		char const QUOTE_CHARACTER = '\'';
		std::string const QUOTE_STRING = "'";
		char const DOUBLE_QUOTE_CHARACTER = '"';
		std::string const DOUBLE_QUOTE_STRING = "\"";
	}

	namespace Name
	{
		namespace Comment
		{
			std::string const BLOCK = "Block comment";
			std::string const LINE = "Line comment";
		}

		namespace Operator
		{
			namespace Arithmetic
			{
				std::string const DIVISION = "Division";
				std::string const MINUS = "Minus";
				std::string const MULTIPLY = "Multiply";
				std::string const PLUS = "Plus";
			}

			namespace Assignment
			{
				std::string const ASSIGNMENT = "Assignment";
				std::string const DIVISION_ASSIGNMENT = "Division assignment";
				std::string const MINUS_ASSIGNMENT = "Minus assignment";
				std::string const MULTIPLY_ASSIGNMENT = "Multiply assignment";
				std::string const PLUS_ASSIGNMENT = "Plus assignment";
			}

			namespace Comparison
			{
				std::string const EQUIVALENCE = "Equivalence";
				std::string const NOT_EQUIVALENCE = "Not equivalence";
				std::string const MORE_OR_EQUIVALENCE = "More or equal";
				std::string const LESS_OR_EQUIVALENCE = "Less or equal";
				std::string const MORE = "More";
				std::string const LESS = "Less";
			}
		}

		namespace Keyword
		{
			std::string const CLASS = "Class keyword";
			std::string const CONSTRUCTOR = "Constructor keyword";
			std::string const DO = "Do keyword";
			std::string const EXTENDS = "Extends keyword";
			std::string const FOR = "For keyword";
			std::string const GET = "Get keyword";
			std::string const IMPLEMENTS = "Implements keyword";
			std::string const NOT_INITIALIZED = "NULL keyword";
			std::string const PRIVATE = "Private keyword";
			std::string const PUBLIC = "Public keyword";
			std::string const RETURN = "Return keyword";
			std::string const SET = "Set keyword";
			std::string const WHILE = "While keyword";
			std::string const IF = "If keyword";
			std::string const ELSE = "Else keyword";
		}

		std::string const INTEGER = "Integer";
		std::string const FLOAT = "Float";
		std::string const EXPONENTIAL = "Exponential";

		namespace Separator
		{
			std::string const DOT = "Dot";
			std::string const COLON = "Colon";
			std::string const COMMA = "Comma";
			std::string const SEMICOLON = "Semicolon";
			std::string const EXPONENT = "Exponent";
		}

		namespace Parentheses
		{
			std::string const CURLY_BRACKET_LEFT = "Left curly bracket";
			std::string const CURLY_BRACKET_RIGHT = "Right curly bracket";
			std::string const ROUND_BRACKET_LEFT = "Left round bracket";
			std::string const ROUND_BRACKET_RIGHT = "Right round bracket";
			std::string const SQUARE_BRACKET_LEFT = "Left square bracket";
			std::string const SQUARE_BRACKET_RIGHT = "Right square bracket";
			std::string const QUOTE_STRING = "Character literal";
			std::string const DOUBLE_QUOTE = "String literal";
		}

		std::string const TYPE = "Type";
		std::string const IDENTIFIER = "Identifier";
		std::string const STRING_LITERAL = "String literal";
		std::string const CHARACTER_LITERAL = "Character literal";
		std::string const UNKNOWN = "Unknown";
	}

	namespace Number
	{
		size_t const DEFAULT_SYSTEM = 10;
		size_t const MAX_SYSTEM = 36;
	}
}

#endif //TOKEN_CONSTANT_H
