#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(public_token, determining_if_stay_alone)
{
	ExpectTokens("public", { Token::PUBLIC });
}

TEST(public_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" public ", { Token::PUBLIC });
	ExpectTokens(";public;", { Token::SEMICOLON, Token::PUBLIC, Token::SEMICOLON });
}

TEST(public_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("public;", { Token::PUBLIC, Token::SEMICOLON });
	ExpectTokens(";public", { Token::SEMICOLON, Token::PUBLIC });
}

TEST(public_token, not_determining_if_between_numbers)
{
	ExpectTokens("1public1", { Token::UNKNOWN });
	ExpectTokens("1public1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1public1", { Token::UNKNOWN });
	ExpectTokens("1.1public1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1public1", { Token::UNKNOWN });
	ExpectTokens("1public1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(public_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"public\"", { Token::STRING_LITERAL });
	ExpectTokens("\" public \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1public1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";public;\"", { Token::STRING_LITERAL });
}

TEST(public_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//public", { });
	ExpectTokens("// public ", { });
	ExpectTokens("//1public1", { });
	ExpectTokens("//;public;", { });
	ExpectTokens("/*public*/", { });
	ExpectTokens("/* public */", { });
	ExpectTokens("/*1public1*/", { });
	ExpectTokens("/*;public;*/", { });
	ExpectTokens("/*public", { });
	ExpectTokens("/* public ", { });
	ExpectTokens("/*1public1", { });
	ExpectTokens("/*;public;", { });
}
