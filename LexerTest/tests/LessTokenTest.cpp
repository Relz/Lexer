#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(less_token, determining_if_stay_alone)
{
	ExpectTokens("<", { Token::LESS });
}

TEST(less_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" < ", { Token::LESS });
	ExpectTokens(";<;", { Token::SEMICOLON, Token::LESS, Token::SEMICOLON });
}

TEST(less_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("<;", { Token::LESS, Token::SEMICOLON });
	ExpectTokens(";<", { Token::SEMICOLON, Token::LESS });
}

TEST(less_token, determining_if_stay_between_numbers)
{
	ExpectTokens("1<1", { Token::INTEGER, Token::LESS, Token::INTEGER });
	ExpectTokens("1<1.1", { Token::INTEGER, Token::LESS, Token::FLOAT });
	ExpectTokens("1.1<1", { Token::FLOAT, Token::LESS, Token::INTEGER });
	ExpectTokens("1.1<1.1", { Token::FLOAT, Token::LESS, Token::FLOAT });
	ExpectTokens("1_E+1<1", { Token::EXPONENTIAL, Token::LESS, Token::INTEGER });
	ExpectTokens("1<1_E+1", { Token::INTEGER, Token::LESS, Token::EXPONENTIAL });
}

TEST(less_token, not_determining_if_in_character_literal)
{
	ExpectTokens("'<'", { Token::CHARACTER_LITERAL });
}

TEST(less_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"<\"", { Token::STRING_LITERAL });
	ExpectTokens("\" < \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1<1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";<;\"", { Token::STRING_LITERAL });
}

TEST(less_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//<", { Token::LINE_COMMENT });
	ExpectTokens("// < ", { Token::LINE_COMMENT });
	ExpectTokens("//1<1", { Token::LINE_COMMENT });
	ExpectTokens("//;<;", { Token::LINE_COMMENT });
	ExpectTokens("/*<*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* < */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1<1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;<;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*<", { Token::BLOCK_COMMENT });
	ExpectTokens("/* < ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1<1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;<;", { Token::BLOCK_COMMENT });
}
