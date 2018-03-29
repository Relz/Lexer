#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(multiply_assignment_token, determining_if_stay_alone)
{
	ExpectTokens("*=", { Token::MULTIPLY_ASSIGNMENT });
}

TEST(multiply_assignment_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" *= ", { Token::MULTIPLY_ASSIGNMENT });
	ExpectTokens(";*=;", { Token::SEMICOLON, Token::MULTIPLY_ASSIGNMENT, Token::SEMICOLON });
}

TEST(multiply_assignment_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("*=;", { Token::MULTIPLY_ASSIGNMENT, Token::SEMICOLON });
	ExpectTokens(";*=", { Token::SEMICOLON, Token::MULTIPLY_ASSIGNMENT });
}

TEST(multiply_assignment_token, determining_if_between_numbers)
{
	ExpectTokens("1*=1", { Token::INTEGER, Token::MULTIPLY_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1*=1.1", { Token::INTEGER, Token::MULTIPLY_ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1.1*=1", { Token::FLOAT, Token::MULTIPLY_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1.1*=1.1", { Token::FLOAT, Token::MULTIPLY_ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1E+1*=1", { Token::EXPONENTIAL, Token::MULTIPLY_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1*=1E+1", { Token::INTEGER, Token::MULTIPLY_ASSIGNMENT, Token::EXPONENTIAL });
}

TEST(multiply_assignment_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"*=\"", { Token::STRING_LITERAL });
	ExpectTokens("\" *= \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1*=1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";*=;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"*=*=*=\"", { Token::STRING_LITERAL });
}

TEST(multiply_assignment_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//*=", { });
	ExpectTokens("// *= ", { });
	ExpectTokens("//1*=1", { });
	ExpectTokens("//;*=;", { });
	ExpectTokens("/**=*/", { });
	ExpectTokens("/* *= */", { });
	ExpectTokens("/*1*=1*/", { });
	ExpectTokens("/*;*=;*/", { });
	ExpectTokens("/**=", { });
	ExpectTokens("/* *= ", { });
	ExpectTokens("/*1*=1", { });
	ExpectTokens("/*;*=;", { });
}
