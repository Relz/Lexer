#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(return_token, determining_if_stay_alone)
{
	ExpectTokens("return", { Token::RETURN });
}

TEST(return_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" return ", { Token::RETURN });
	ExpectTokens(";return;", { Token::SEMICOLON, Token::RETURN, Token::SEMICOLON });
}

TEST(return_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("return;", { Token::RETURN, Token::SEMICOLON });
	ExpectTokens(";return", { Token::SEMICOLON, Token::RETURN });
}

TEST(return_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1return1", { Token::UNKNOWN });
	ExpectTokens("1return1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1return1", { Token::UNKNOWN });
	ExpectTokens("1.1return1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1return1", { Token::UNKNOWN });
	ExpectTokens("1return1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(return_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"return\"", { Token::STRING_LITERAL });
	ExpectTokens("\" return \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1return1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";return;\"", { Token::STRING_LITERAL });
}

TEST(return_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//return", { });
	ExpectTokens("// return ", { });
	ExpectTokens("//1return1", { });
	ExpectTokens("//;return;", { });
	ExpectTokens("/*return*/", { });
	ExpectTokens("/* return */", { });
	ExpectTokens("/*1return1*/", { });
	ExpectTokens("/*;return;*/", { });
	ExpectTokens("/*return", { });
	ExpectTokens("/* return ", { });
	ExpectTokens("/*1return1", { });
	ExpectTokens("/*;return;", { });
}
