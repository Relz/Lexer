#include "TestHelper.h"

using namespace std;

TEST(get_token, determining_if_stay_alone)
{
	ExpectTokens("get", { Token::GET });
}

TEST(get_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" get ", { Token::GET });
	ExpectTokens(";get;", { Token::SEMICOLON, Token::GET, Token::SEMICOLON });
}

TEST(get_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("get;", { Token::GET, Token::SEMICOLON });
	ExpectTokens(";get", { Token::SEMICOLON, Token::GET });
}

TEST(get_token, not_determining_if_between_numbers)
{
	ExpectTokens("1get1", { Token::UNKNOWN });
	ExpectTokens("1get1.1", { Token::UNKNOWN });
	ExpectTokens("1.1get1", { Token::UNKNOWN });
	ExpectTokens("1.1get1.1", { Token::UNKNOWN });
	ExpectTokens("1E+1get1", { Token::UNKNOWN });
	ExpectTokens("1get1E+1", { Token::UNKNOWN });
}

TEST(get_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"get\"", { Token::STRING_LITERAL });
	ExpectTokens("\" get \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1get1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";get;\"", { Token::STRING_LITERAL });
}

TEST(get_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//get", { });
	ExpectTokens("// get ", { });
	ExpectTokens("//1get1", { });
	ExpectTokens("//;get;", { });
	ExpectTokens("/*get*/", { });
	ExpectTokens("/* get */", { });
	ExpectTokens("/*1get1*/", { });
	ExpectTokens("/*;get;*/", { });
	ExpectTokens("/*get", { });
	ExpectTokens("/* get ", { });
	ExpectTokens("/*1get1", { });
	ExpectTokens("/*;get;", { });
}
