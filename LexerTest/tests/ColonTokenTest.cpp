#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(colon_token, determining_if_stay_alone)
{
	ExpectTokens(":", { Token::COLON });
}

TEST(colon_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" : ", { Token::COLON });
	ExpectTokens(";:;", { Token::SEMICOLON, Token::COLON, Token::SEMICOLON });
}

TEST(colon_token, determining_if_stay_near_delimiter)
{
	ExpectTokens(":;", { Token::COLON, Token::SEMICOLON });
	ExpectTokens(";:", { Token::SEMICOLON, Token::COLON });
}

TEST(colon_token, determining_if_stay_between_numbers)
{
	ExpectTokens("1:1", { Token::INTEGER, Token::COLON, Token::INTEGER });
	ExpectTokens("1:1.1", { Token::INTEGER, Token::COLON, Token::FLOAT });
	ExpectTokens("1.1:1", { Token::FLOAT, Token::COLON, Token::INTEGER });
	ExpectTokens("1.1:1.1", { Token::FLOAT, Token::COLON, Token::FLOAT });
	ExpectTokens("1_E+1:1", { Token::EXPONENTIAL, Token::COLON, Token::INTEGER });
	ExpectTokens("1:1_E+1", { Token::INTEGER, Token::COLON, Token::EXPONENTIAL });
}

TEST(colon_token, not_determining_if_in_character_literal)
{
	ExpectTokens("':'", { Token::CHARACTER_LITERAL });
}

TEST(colon_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\":\"", { Token::STRING_LITERAL });
	ExpectTokens("\" : \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1:1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";:;\"", { Token::STRING_LITERAL });
}

TEST(colon_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//:", { });
	ExpectTokens("// : ", { });
	ExpectTokens("//1:1", { });
	ExpectTokens("//;:;", { });
	ExpectTokens("/*:*/", { });
	ExpectTokens("/* : */", { });
	ExpectTokens("/*1:1*/", { });
	ExpectTokens("/*;:;*/", { });
	ExpectTokens("/*:", { });
	ExpectTokens("/* : ", { });
	ExpectTokens("/*1:1", { });
	ExpectTokens("/*;:;", { });
}
