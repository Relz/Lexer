#ifndef TOKEN_CONSTANT_H
#define TOKEN_CONSTANT_H

#include <string>
#include <vector>
#include "Parenthesis.h"

namespace Constant
{
	namespace Comment
	{
		const std::string BLOCK_BEGINNING = "/*";
		const std::string BLOCK_ENDING = "*/";
		const std::string LINE = "//";
	}

	namespace Operator
	{
		namespace Arithmetic
		{
			const std::string DIVISION = "/";
			const std::string MINUS = "-";
			const char MINUS_CHARACTER = '-';
			const std::string MULTIPLY = "*";
			const std::string PLUS = "+";
			const char PLUS_CHARACTER = '+';
		};

		namespace Assignment
		{
			const std::string ASSIGNMENT = "=";
			const std::string DIVISION_ASSIGNMENT = "/=";
			const std::string MINUS_ASSIGNMENT = "-=";
			const std::string MULTIPLY_ASSIGNMENT = "*=";
			const std::string PLUS_ASSIGNMENT = "+=";
		}

		namespace Comparison
		{
			const std::string EQUIVALENCE = "==";
			const std::string NOT_EQUIVALENCE = "!=";
			const std::string MORE_OR_EQUIVALENCE = ">=";
			const std::string LESS_OR_EQUIVALENCE = "<=";
			const std::string MORE = ">";
			const std::string LESS = "<";
		}
	}

	namespace Keyword
	{
		const std::string CLASS = "class";
		const std::string CONSTRUCTOR = "Constructor";
		const std::string DO = "do";
		const std::string EXTENDS = "extends";
		const std::string FOR = "for";
		const std::string GET = "get";
		const std::string IMPLEMENTS = "implements";
		const std::string NOT_INITIALIZED = "NULL";
		const std::string PRIVATE = "private";
		const std::string PUBLIC = "public";
		const std::string RETURN = "return";
		const std::string SET = "set";
		const std::string WHILE = "while";
		const std::string IF = "if";
		const std::string ELSE = "else";
	}

	namespace CoreType
	{
		namespace Number
		{
			const std::string DOUBLE = "Double";
			const std::string FLOAT = "Float";
			const std::string INTEGER = "Integer";
		};

		namespace Complex
		{
			const std::string ARRAY = "Array";
			const std::string STRING = "String";
		}

		const std::string VOID = "Void";
	}

	namespace Separator
	{
		const std::string DOT = ".";
		const char DOT_CHARACTER = '.';
		const std::string COLON = ":";
		const std::string COMMA = ",";
		const std::string SEMICOLON = ";";
		const std::string EXPONENT = "E";
		const char EXPONENT_CHARACTER = 'E';
		const std::string SPACE = " ";
		const std::string TAB = "\t";
		const std::string END_OF_LINE_LF = "\n";
		const std::string END_OF_LINE_CR = "\r";
		const std::string END_OF_LINE_CRLF = "\r\n";
		const std::string UNDERSCORE = "_";
		const char UNDERSCORE_CHARACTER = '_';
	}

	namespace Parentheses
	{
		const Parenthesis ANGLE_BRACKET = {"<", ">"};
		const Parenthesis CURLY_BRACKET = {"{", "}"};
		const Parenthesis ROUND_BRACKET = {"(", ")"};
		const Parenthesis SQUARE_BRACKET = {"[", "]"};
		const char QUOTE_CHARACTER = '\'';
		const std::string QUOTE_STRING = "'";
		const char DOUBLE_QUOTE_CHARACTER = '"';
		const std::string DOUBLE_QUOTE = "\"";
	}

	namespace Name
	{
		namespace Comment
		{
			const std::string BLOCK = "Block comment";
			const std::string LINE = "Line comment";
		}

		namespace Operator
		{
			namespace Arithmetic
			{
				const std::string DIVISION = "Division";
				const std::string MINUS = "Minus";
				const std::string MULTIPLY = "Multiply";
				const std::string PLUS = "Plus";
			}

			namespace Assignment
			{
				const std::string ASSIGNMENT = "Assignment";
				const std::string DIVISION_ASSIGNMENT = "Division assignment";
				const std::string MINUS_ASSIGNMENT = "Minus assignment";
				const std::string MULTIPLY_ASSIGNMENT = "Multiply assignment";
				const std::string PLUS_ASSIGNMENT = "Plus assignment";
			}

			namespace Comparison
			{
				const std::string EQUIVALENCE = "Equivalence";
				const std::string NOT_EQUIVALENCE = "Not equivalence";
				const std::string MORE_OR_EQUIVALENCE = "More or equal";
				const std::string LESS_OR_EQUIVALENCE = "Less or equal";
				const std::string MORE = "More";
				const std::string LESS = "Less";
			}
		}

		namespace Keyword
		{
			const std::string CLASS = "Class keyword";
			const std::string CONSTRUCTOR = "Constructor keyword";
			const std::string DO = "Do keyword";
			const std::string EXTENDS = "Extends keyword";
			const std::string FOR = "For keyword";
			const std::string GET = "Get keyword";
			const std::string IMPLEMENTS = "Implements keyword";
			const std::string NOT_INITIALIZED = "NULL keyword";
			const std::string PRIVATE = "Private keyword";
			const std::string PUBLIC = "Public keyword";
			const std::string RETURN = "Return keyword";
			const std::string SET = "Set keyword";
			const std::string WHILE = "While keyword";
			const std::string IF = "If keyword";
			const std::string ELSE = "Else keyword";
		}

		const std::string INTEGER = "Integer";
		const std::string FLOAT = "Float";
		const std::string EXPONENTIAL = "Exponential";

		namespace Separator
		{
			const std::string DOT = "Dot";
			const std::string COLON = "Colon";
			const std::string COMMA = "Comma";
			const std::string SEMICOLON = "Semicolon";
			const std::string EXPONENT = "Exponent";
		}

		namespace Parentheses
		{
			const std::string ANGLE_BRACKET_LEFT = "Left angle bracket";
			const std::string ANGLE_BRACKET_RIGHT = "Right angle bracket";
			const std::string CURLY_BRACKET_LEFT = "Left curly bracket";
			const std::string CURLY_BRACKET_RIGHT = "Right curly bracket";
			const std::string ROUND_BRACKET_LEFT = "Left round bracket";
			const std::string ROUND_BRACKET_RIGHT = "Right round bracket";
			const std::string SQUARE_BRACKET_LEFT = "Left square bracket";
			const std::string SQUARE_BRACKET_RIGHT = "Right square bracket";
			const std::string QUOTE_STRING = "Character literal";
			const std::string DOUBLE_QUOTE = "String literal";
		}

		const std::string TYPE = "Type";
		const std::string IDENTIFIER = "Identifier";
		const std::string STRING_LITERAL = "String literal";
		const std::string CHARACTER_LITERAL = "Character literal";
		const std::string UNKNOWN = "Unknown";
	}

	namespace Number
	{
		const size_t DEFAULT_SYSTEM = 10;
		const size_t MAX_SYSTEM = 36;
	}
}

#endif //TOKEN_CONSTANT_H
