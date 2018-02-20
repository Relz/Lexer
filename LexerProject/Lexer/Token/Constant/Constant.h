#ifndef TOKEN_CONSTANT_H
#define TOKEN_CONSTANT_H

#include <string>
#include <vector>
#include "Parenthesis.h"

using namespace std;

namespace Constant
{
	namespace Comment
	{
		const string BLOCK_BEGINNING = "/*";
		const string BLOCK_ENDING = "*/";
		const string LINE = "//";
	}

	namespace Operator
	{
		namespace Arithmetic
		{
			const string DIVISION = "/";
			const string MINUS = "-";
			const char MINUS_CHARACTER = '-';
			const string MULTIPLY = "*";
			const string PLUS = "+";
			const char PLUS_CHARACTER = '+';
		};

		namespace Assignment
		{
			const string ASSIGNMENT = "=";
			const string DIVISION_ASSIGNMENT = "/=";
			const string MINUS_ASSIGNMENT = "-=";
			const string MULTIPLY_ASSIGNMENT = "*=";
			const string PLUS_ASSIGNMENT = "+=";
		}

		namespace Comparison
		{
			const string EQUIVALENCE = "==";
			const string NOT_EQUIVALENCE = "!=";
			const string MORE_OR_EQUIVALENCE = ">=";
			const string LESS_OR_EQUIVALENCE = "<=";
			const string MORE = ">";
			const string LESS = "<";
		}
	}

	namespace Keyword
	{
		const string CLASS = "class";
		const string CONSTRUCTOR = "Constructor";
		const string DO = "do";
		const string EXTENDS = "extends";
		const string FOR = "for";
		const string GET = "get";
		const string IMPLEMENTS = "implements";
		const string NOT_INITIALIZED = "NULL";
		const string PRIVATE = "private";
		const string PUBLIC = "public";
		const string RETURN = "return";
		const string SET = "set";
		const string WHILE = "while";
		const string IF = "if";
		const string ELSE = "else";
	}

	namespace CoreType
	{
		namespace Number
		{
			const string DOUBLE = "Double";
			const string FLOAT = "Float";
			const string INTEGER = "Integer";
		};

		namespace Complex
		{
			const string ARRAY = "Array";
			const string STRING = "String";
		}

		const string VOID = "Void";
	}

	namespace Separator
	{
		const string DOT = ".";
		const char DOT_CHARACTER = '.';
		const string COLON = ":";
		const string COMMA = ",";
		const string SEMICOLON = ";";
		const string EXPONENT = "E";
		const char EXPONENT_CHARACTER = 'E';
		const string SPACE = " ";
		const string TAB = "\t";
		const string END_OF_LINE_LF = "\n";
		const string END_OF_LINE_CR = "\r";
		const string END_OF_LINE_CRLF = "\r\n";
		const string UNDERSCORE = "_";
		const char UNDERSCORE_CHARACTER = '_';
	}

	namespace Parentheses
	{
		const Parenthesis ANGLE_BRACKET = {"<", ">"};
		const Parenthesis CURLY_BRACKET = {"{", "}"};
		const Parenthesis ROUND_BRACKET = {"(", ")"};
		const Parenthesis SQUARE_BRACKET = {"[", "]"};
		const char QUOTE_CHARACTER = '\'';
		const string QUOTE_STRING = "'";
		const char DOUBLE_QUOTE_CHARACTER = '"';
		const string DOUBLE_QUOTE = "\"";
	}

	namespace Name
	{
		namespace Comment
		{
			const string BLOCK = "Block comment";
			const string LINE = "Line comment";
		}

		namespace Operator
		{
			namespace Arithmetic
			{
				const string DIVISION = "Division";
				const string MINUS = "Minus";
				const string MULTIPLY = "Multiply";
				const string PLUS = "Plus";
			}

			namespace Assignment
			{
				const string ASSIGNMENT = "Assignment";
				const string DIVISION_ASSIGNMENT = "Division assignment";
				const string MINUS_ASSIGNMENT = "Minus assignment";
				const string MULTIPLY_ASSIGNMENT = "Multiply assignment";
				const string PLUS_ASSIGNMENT = "Plus assignment";
			}

			namespace Comparison
			{
				const string EQUIVALENCE = "Equivalence";
				const string NOT_EQUIVALENCE = "Not equivalence";
				const string MORE_OR_EQUIVALENCE = "More or equal";
				const string LESS_OR_EQUIVALENCE = "Less or equal";
				const string MORE = "More";
				const string LESS = "Less";
			}
		}

		namespace Keyword
		{
			const string CLASS = "Class keyword";
			const string CONSTRUCTOR = "Constructor keyword";
			const string DO = "Do keyword";
			const string EXTENDS = "Extends keyword";
			const string FOR = "For keyword";
			const string GET = "Get keyword";
			const string IMPLEMENTS = "Implements keyword";
			const string NOT_INITIALIZED = "NULL keyword";
			const string PRIVATE = "Private keyword";
			const string PUBLIC = "Public keyword";
			const string RETURN = "Return keyword";
			const string SET = "Set keyword";
			const string WHILE = "While keyword";
			const string IF = "If keyword";
			const string ELSE = "Else keyword";
		}

		const string INTEGER = "Integer";
		const string FLOAT = "Float";
		const string EXPONENTIAL = "Exponential";

		namespace Separator
		{
			const string DOT = "Dot";
			const string COLON = "Colon";
			const string COMMA = "Comma";
			const string SEMICOLON = "Semicolon";
			const string EXPONENT = "Exponent";
		}

		namespace Parentheses
		{
			const string ANGLE_BRACKET_LEFT = "Left angle bracket";
			const string ANGLE_BRACKET_RIGHT = "Right angle bracket";
			const string CURLY_BRACKET_LEFT = "Left curly bracket";
			const string CURLY_BRACKET_RIGHT = "Right curly bracket";
			const string ROUND_BRACKET_LEFT = "Left round bracket";
			const string ROUND_BRACKET_RIGHT = "Right round bracket";
			const string SQUARE_BRACKET_LEFT = "Left square bracket";
			const string SQUARE_BRACKET_RIGHT = "Right square bracket";
			const string QUOTE_STRING = "Character literal";
			const string DOUBLE_QUOTE = "String literal";
		}

		const string TYPE = "Type";
		const string IDENTIFIER = "Identifier";
		const string STRING_LITERAL = "String literal";
		const string CHARACTER_LITERAL = "Character literal";
		const string UNKNOWN = "Unknown";
	}

	namespace Number
	{
		const size_t DEFAULT_SYSTEM = 10;
		const size_t MAX_SYSTEM = 36;
	}
}

#endif //TOKEN_CONSTANT_H
