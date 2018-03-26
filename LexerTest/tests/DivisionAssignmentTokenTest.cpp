#include "TestHelper.h"

using namespace std;

TEST(division_assignment_token, determining_if_stay_alone)
{
	ExpectTokens("/=", { Token::DIVISION_ASSIGNMENT });
}

TEST(division_assignment_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" /= ", { Token::DIVISION_ASSIGNMENT });
	ExpectTokens(";/=;", { Token::SEMICOLON, Token::DIVISION_ASSIGNMENT, Token::SEMICOLON });
}

TEST(division_assignment_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("/=;", { Token::DIVISION_ASSIGNMENT, Token::SEMICOLON });
	ExpectTokens(";/=", { Token::SEMICOLON, Token::DIVISION_ASSIGNMENT });
}

TEST(division_assignment_token, determining_if_between_numbers)
{
	ExpectTokens("1/=1", { Token::INTEGER, Token::DIVISION_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1/=1.1", { Token::INTEGER, Token::DIVISION_ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1.1/=1", { Token::FLOAT, Token::DIVISION_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1.1/=1.1", { Token::FLOAT, Token::DIVISION_ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1E+1/=1", { Token::EXPONENTIAL, Token::DIVISION_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1/=1E+1", { Token::INTEGER, Token::DIVISION_ASSIGNMENT, Token::EXPONENTIAL });
}

TEST(division_assignment_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"/=\"", { Token::STRING_LITERAL });
	ExpectTokens("\" /= \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1/=1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";/=;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"/=/=/=\"", { Token::STRING_LITERAL });
}

TEST(division_assignment_token, not_determining_if_part_of_comment)
{
	ExpectTokens("///=", { });
	ExpectTokens("// /= ", { });
	ExpectTokens("//1/=1", { });
	ExpectTokens("//;/=;", { });
	ExpectTokens("/*/=*/", { });
	ExpectTokens("/* /= */", { });
	ExpectTokens("/*1/=1*/", { });
	ExpectTokens("/*;/=;*/", { });
	ExpectTokens("/*/=", { });
	ExpectTokens("/* /= ", { });
	ExpectTokens("/*1/=1", { });
	ExpectTokens("/*;/=;", { });
}
