#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(constructor_token, determining_if_stay_alone)
{
	ExpectTokens("Constructor", { Token::CONSTRUCTOR });
}

TEST(constructor_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" Constructor ", { Token::CONSTRUCTOR });
	ExpectTokens(";Constructor;", { Token::SEMICOLON, Token::CONSTRUCTOR, Token::SEMICOLON });
}

TEST(constructor_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("Constructor;", { Token::CONSTRUCTOR, Token::SEMICOLON });
	ExpectTokens(";Constructor", { Token::SEMICOLON, Token::CONSTRUCTOR });
}

TEST(constructor_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1Constructor1", { Token::UNKNOWN });
	ExpectTokens("1Constructor1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1Constructor1", { Token::UNKNOWN });
	ExpectTokens("1.1Constructor1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1Constructor1", { Token::UNKNOWN });
	ExpectTokens("1Constructor1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(constructor_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"Constructor\"", { Token::STRING_LITERAL });
	ExpectTokens("\" Constructor \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1Constructor1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";Constructor;\"", { Token::STRING_LITERAL });
}

TEST(constructor_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//Constructor", { Token::LINE_COMMENT });
	ExpectTokens("// Constructor ", { Token::LINE_COMMENT });
	ExpectTokens("//1Constructor1", { Token::LINE_COMMENT });
	ExpectTokens("//;Constructor;", { Token::LINE_COMMENT });
	ExpectTokens("/*Constructor*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* Constructor */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1Constructor1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;Constructor;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*Constructor", { Token::BLOCK_COMMENT });
	ExpectTokens("/* Constructor ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1Constructor1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;Constructor;", { Token::BLOCK_COMMENT });
}
