#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(comma_token, determining_if_stay_alone)
{
	ExpectTokens(",", { Token::COMMA });
}

TEST(comma_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" , ", { Token::COMMA });
	ExpectTokens(";,;", { Token::SEMICOLON, Token::COMMA, Token::SEMICOLON });
}

TEST(comma_token, determining_if_stay_near_delimiter)
{
	ExpectTokens(",;", { Token::COMMA, Token::SEMICOLON });
	ExpectTokens(";,", { Token::SEMICOLON, Token::COMMA });
}

TEST(comma_token, determining_if_between_numbers)
{
	ExpectTokens("1,1", { Token::INTEGER, Token::COMMA, Token::INTEGER });
	ExpectTokens("1,1.1", { Token::INTEGER, Token::COMMA, Token::FLOAT });
	ExpectTokens("1.1,1", { Token::FLOAT, Token::COMMA, Token::INTEGER });
	ExpectTokens("1.1,1.1", { Token::FLOAT, Token::COMMA, Token::FLOAT });
	ExpectTokens("1_E+1,1", { Token::EXPONENTIAL, Token::COMMA, Token::INTEGER });
	ExpectTokens("1,1_E+1", { Token::INTEGER, Token::COMMA, Token::EXPONENTIAL });
}

TEST(comma_token, not_determining_if_in_character_literal)
{
	ExpectTokens("','", { Token::CHARACTER_LITERAL });
}

TEST(comma_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\",\"", { Token::STRING_LITERAL });
	ExpectTokens("\" , \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1,1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";,;\"", { Token::STRING_LITERAL });
}

TEST(comma_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//,", { });
	ExpectTokens("// , ", { });
	ExpectTokens("//1,1", { });
	ExpectTokens("//;,;", { });
	ExpectTokens("/*,*/", { });
	ExpectTokens("/* , */", { });
	ExpectTokens("/*1,1*/", { });
	ExpectTokens("/*;,;*/", { });
	ExpectTokens("/*,", { });
	ExpectTokens("/* , ", { });
	ExpectTokens("/*1,1", { });
	ExpectTokens("/*;,;", { });
}
