#include "TestHelper.h"

using namespace std;

TEST(minus_assignment_token, determining_if_stay_alone)
{
	ExpectTokens("-=", { Token::MINUS_ASSIGNMENT });
}

TEST(minus_assignment_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" -= ", { Token::MINUS_ASSIGNMENT });
	ExpectTokens(";-=;", { Token::SEMICOLON, Token::MINUS_ASSIGNMENT, Token::SEMICOLON });
}

TEST(minus_assignment_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("-=;", { Token::MINUS_ASSIGNMENT, Token::SEMICOLON });
	ExpectTokens(";-=", { Token::SEMICOLON, Token::MINUS_ASSIGNMENT });
}

TEST(minus_assignment_token, determining_if_between_numbers)
{
	ExpectTokens("1-=1", { Token::INTEGER, Token::MINUS_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1-=1.1", { Token::INTEGER, Token::MINUS_ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1.1-=1", { Token::FLOAT, Token::MINUS_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1.1-=1.1", { Token::FLOAT, Token::MINUS_ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1E-1-=1", { Token::EXPONENTIAL, Token::MINUS_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1-=1E-1", { Token::INTEGER, Token::MINUS_ASSIGNMENT, Token::EXPONENTIAL });
}

TEST(minus_assignment_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"-=\"", { Token::STRING_LITERAL });
	ExpectTokens("\" -= \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1-=1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";-=;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"-=-=-=\"", { Token::STRING_LITERAL });
}

TEST(minus_assignment_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//-=", { });
	ExpectTokens("// -= ", { });
	ExpectTokens("//1-=1", { });
	ExpectTokens("//;-=;", { });
	ExpectTokens("/*-=*/", { });
	ExpectTokens("/* -= */", { });
	ExpectTokens("/*1-=1*/", { });
	ExpectTokens("/*;-=;*/", { });
	ExpectTokens("/*-=", { });
	ExpectTokens("/* -= ", { });
	ExpectTokens("/*1-=1", { });
	ExpectTokens("/*;-=;", { });
}
