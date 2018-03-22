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

TEST(less_token, determining_if_between_numbers)
{
	ExpectTokens("1<1", { Token::INTEGER, Token::LESS, Token::INTEGER });
	ExpectTokens("1<1.1", { Token::INTEGER, Token::LESS, Token::FLOAT });
	ExpectTokens("1.1<1", { Token::FLOAT, Token::LESS, Token::INTEGER });
	ExpectTokens("1.1<1.1", { Token::FLOAT, Token::LESS, Token::FLOAT });
	ExpectTokens("1E+1<1", { Token::EXPONENTIAL, Token::LESS, Token::INTEGER });
	ExpectTokens("1<1E+1", { Token::INTEGER, Token::LESS, Token::EXPONENTIAL });
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
	ExpectTokens("//<", { });
	ExpectTokens("// < ", { });
	ExpectTokens("//1<1", { });
	ExpectTokens("//;<;", { });
	ExpectTokens("/*<*/", { });
	ExpectTokens("/* < */", { });
	ExpectTokens("/*1<1*/", { });
	ExpectTokens("/*;<;*/", { });
	ExpectTokens("/*<", { });
	ExpectTokens("/* < ", { });
	ExpectTokens("/*1<1", { });
	ExpectTokens("/*;<;", { });
}
