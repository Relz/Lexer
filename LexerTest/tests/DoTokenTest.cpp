#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(do_token, determining_if_stay_alone)
{
	ExpectTokens("do", { Token::DO });
}

TEST(do_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" do ", { Token::DO });
	ExpectTokens(";do;", { Token::SEMICOLON, Token::DO, Token::SEMICOLON });
}

TEST(do_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("do;", { Token::DO, Token::SEMICOLON });
	ExpectTokens(";do", { Token::SEMICOLON, Token::DO });
}

TEST(do_token, not_determining_if_between_numbers)
{
	ExpectTokens("1do1", { Token::UNKNOWN });
	ExpectTokens("1do1.1", { Token::UNKNOWN });
	ExpectTokens("1.1do1", { Token::UNKNOWN });
	ExpectTokens("1.1do1.1", { Token::UNKNOWN });
	ExpectTokens("1E+1do1", { Token::UNKNOWN });
	ExpectTokens("1do1E+1", { Token::UNKNOWN });
}

TEST(do_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"do\"", { Token::STRING_LITERAL });
	ExpectTokens("\" do \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1do1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";do;\"", { Token::STRING_LITERAL });
}

TEST(do_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//do", { });
	ExpectTokens("// do ", { });
	ExpectTokens("//1do1", { });
	ExpectTokens("//;do;", { });
	ExpectTokens("/*do*/", { });
	ExpectTokens("/* do */", { });
	ExpectTokens("/*1do1*/", { });
	ExpectTokens("/*;do;*/", { });
	ExpectTokens("/*do", { });
	ExpectTokens("/* do ", { });
	ExpectTokens("/*1do1", { });
	ExpectTokens("/*;do;", { });
}
