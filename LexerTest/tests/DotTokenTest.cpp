#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(dot_token, determining_if_stay_alone)
{
	ExpectTokens(".", { Token::DOT });
}

TEST(dot_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" . ", { Token::DOT });
	ExpectTokens(";.;", { Token::SEMICOLON, Token::DOT, Token::SEMICOLON });
}

TEST(dot_token, determining_if_stay_near_delimiter)
{
	ExpectTokens(".;", { Token::DOT, Token::SEMICOLON });
	ExpectTokens(";.", { Token::SEMICOLON, Token::DOT });
}

TEST(dot_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1.1", { Token::FLOAT });
	ExpectTokens("1.1.1", { Token::UNKNOWN });
	ExpectTokens("1_E+1.1", { Token::EXPONENTIAL });
	ExpectTokens("1.1_E+1", { Token::EXPONENTIAL });
}

TEST(dot_token, not_determining_if_in_character_literal)
{
	ExpectTokens("'.'", { Token::CHARACTER_LITERAL });
}

TEST(dot_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\".\"", { Token::STRING_LITERAL });
	ExpectTokens("\" . \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1.1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";.;\"", { Token::STRING_LITERAL });
}

TEST(dot_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//.", { Token::LINE_COMMENT });
	ExpectTokens("// . ", { Token::LINE_COMMENT });
	ExpectTokens("//1.1", { Token::LINE_COMMENT });
	ExpectTokens("//;.;", { Token::LINE_COMMENT });
	ExpectTokens("/*.*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* . */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1.1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;.;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*.", { Token::BLOCK_COMMENT });
	ExpectTokens("/* . ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1.1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;.;", { Token::BLOCK_COMMENT });
}
