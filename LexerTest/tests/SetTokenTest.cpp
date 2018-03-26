#include "TestHelper.h"

using namespace std;

TEST(set_token, determining_if_stay_alone)
{
	ExpectTokens("set", { Token::SET });
}

TEST(set_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" set ", { Token::SET });
	ExpectTokens(";set;", { Token::SEMICOLON, Token::SET, Token::SEMICOLON });
}

TEST(set_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("set;", { Token::SET, Token::SEMICOLON });
	ExpectTokens(";set", { Token::SEMICOLON, Token::SET });
}

TEST(set_token, not_determining_if_between_numbers)
{
	ExpectTokens("1set1", { Token::UNKNOWN });
	ExpectTokens("1set1.1", { Token::UNKNOWN });
	ExpectTokens("1.1set1", { Token::UNKNOWN });
	ExpectTokens("1.1set1.1", { Token::UNKNOWN });
	ExpectTokens("1E+1set1", { Token::UNKNOWN });
	ExpectTokens("1set1E+1", { Token::UNKNOWN });
}

TEST(set_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"set\"", { Token::STRING_LITERAL });
	ExpectTokens("\" set \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1set1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";set;\"", { Token::STRING_LITERAL });
}

TEST(set_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//set", { });
	ExpectTokens("// set ", { });
	ExpectTokens("//1set1", { });
	ExpectTokens("//;set;", { });
	ExpectTokens("/*set*/", { });
	ExpectTokens("/* set */", { });
	ExpectTokens("/*1set1*/", { });
	ExpectTokens("/*;set;*/", { });
	ExpectTokens("/*set", { });
	ExpectTokens("/* set ", { });
	ExpectTokens("/*1set1", { });
	ExpectTokens("/*;set;", { });
}
