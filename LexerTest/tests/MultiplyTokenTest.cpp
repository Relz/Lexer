#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(multiply_token, determining_if_stay_alone)
{
	ExpectTokens("*", { Token::MULTIPLY });
}

TEST(multiply_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" * ", { Token::MULTIPLY });
	ExpectTokens(";*;", { Token::SEMICOLON, Token::MULTIPLY, Token::SEMICOLON });
}

TEST(multiply_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("*;", { Token::MULTIPLY, Token::SEMICOLON });
	ExpectTokens(";*", { Token::SEMICOLON, Token::MULTIPLY });
}

TEST(multiply_token, determining_if_between_numbers)
{
	ExpectTokens("1*1", { Token::INTEGER, Token::MULTIPLY, Token::INTEGER });
	ExpectTokens("1*1.1", { Token::INTEGER, Token::MULTIPLY, Token::FLOAT });
	ExpectTokens("1.1*1", { Token::FLOAT, Token::MULTIPLY, Token::INTEGER });
	ExpectTokens("1.1*1.1", { Token::FLOAT, Token::MULTIPLY, Token::FLOAT });
	ExpectTokens("1_E+1*1", { Token::EXPONENTIAL, Token::MULTIPLY, Token::INTEGER });
	ExpectTokens("1*1_E+1", { Token::INTEGER, Token::MULTIPLY, Token::EXPONENTIAL });
}

TEST(multiply_token, not_determining_if_part_of_plus_assignment)
{
	ExpectTokens("*=", { Token::MULTIPLY_ASSIGNMENT });
	ExpectTokens("**=", { Token::MULTIPLY, Token::MULTIPLY_ASSIGNMENT });
	ExpectTokens("*=*", { Token::MULTIPLY_ASSIGNMENT, Token::MULTIPLY });
}

TEST(multiply_token, not_determining_if_in_character_literal)
{
	ExpectTokens("'*'", { Token::CHARACTER_LITERAL });
}

TEST(multiply_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"*\"", { Token::STRING_LITERAL });
	ExpectTokens("\" * \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1*1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";*;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"***\"", { Token::STRING_LITERAL });
}

TEST(multiply_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//*", {});
	ExpectTokens("// * ", {});
	ExpectTokens("//1*1", {});
	ExpectTokens("//;*;", {});
	ExpectTokens("//***", {});
	ExpectTokens("/***/", {});
	ExpectTokens("/* * */", {});
	ExpectTokens("/*1*1*/", {});
	ExpectTokens("/*;*;*/", {});
	ExpectTokens("/*****/", {});
	ExpectTokens("/**", {});
	ExpectTokens("/* * ", {});
	ExpectTokens("/*1*1", {});
	ExpectTokens("/*;*;", {});
	ExpectTokens("/****", {});
}
