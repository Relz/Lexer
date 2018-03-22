#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(plus_assignment_token, determining_if_stay_alone)
{
	ExpectTokens("+=", { Token::PLUS_ASSIGNMENT });
}

TEST(plus_assignment_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" += ", { Token::PLUS_ASSIGNMENT });
	ExpectTokens(";+=;", { Token::SEMICOLON, Token::PLUS_ASSIGNMENT, Token::SEMICOLON });
}

TEST(plus_assignment_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("+=;", { Token::PLUS_ASSIGNMENT, Token::SEMICOLON });
	ExpectTokens(";+=", { Token::SEMICOLON, Token::PLUS_ASSIGNMENT });
}

TEST(plus_assignment_token, determining_if_between_numbers)
{
	ExpectTokens("1+=1", { Token::INTEGER, Token::PLUS_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1+=1.1", { Token::INTEGER, Token::PLUS_ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1.1+=1", { Token::FLOAT, Token::PLUS_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1.1+=1.1", { Token::FLOAT, Token::PLUS_ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1E+1+=1", { Token::EXPONENTIAL, Token::PLUS_ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1+=1E+1", { Token::INTEGER, Token::PLUS_ASSIGNMENT, Token::EXPONENTIAL });
}

TEST(plus_assignment_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"+=\"", { Token::STRING_LITERAL });
	ExpectTokens("\" += \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1+=1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";+=;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"+=+=+=\"", { Token::STRING_LITERAL });
}

TEST(plus_assignment_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//+=", { });
	ExpectTokens("// += ", { });
	ExpectTokens("//1+=1", { });
	ExpectTokens("//;+=;", { });
	ExpectTokens("/*+=*/", { });
	ExpectTokens("/* += */", { });
	ExpectTokens("/*1+=1*/", { });
	ExpectTokens("/*;+=;*/", { });
	ExpectTokens("/*+=", { });
	ExpectTokens("/* += ", { });
	ExpectTokens("/*1+=1", { });
	ExpectTokens("/*;+=;", { });
}
