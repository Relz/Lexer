#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(private_token, determining_if_stay_alone)
{
	ExpectTokens("private", { Token::PRIVATE });
}

TEST(private_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" private ", { Token::PRIVATE });
	ExpectTokens(";private;", { Token::SEMICOLON, Token::PRIVATE, Token::SEMICOLON });
}

TEST(private_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("private;", { Token::PRIVATE, Token::SEMICOLON });
	ExpectTokens(";private", { Token::SEMICOLON, Token::PRIVATE });
}

TEST(private_token, not_determining_if_between_numbers)
{
	ExpectTokens("1private1", { Token::UNKNOWN });
	ExpectTokens("1private1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1private1", { Token::UNKNOWN });
	ExpectTokens("1.1private1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1E+1private1", { Token::UNKNOWN });
	ExpectTokens("1private1E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(private_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"private\"", { Token::STRING_LITERAL });
	ExpectTokens("\" private \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1private1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";private;\"", { Token::STRING_LITERAL });
}

TEST(private_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//private", { });
	ExpectTokens("// private ", { });
	ExpectTokens("//1private1", { });
	ExpectTokens("//;private;", { });
	ExpectTokens("/*private*/", { });
	ExpectTokens("/* private */", { });
	ExpectTokens("/*1private1*/", { });
	ExpectTokens("/*;private;*/", { });
	ExpectTokens("/*private", { });
	ExpectTokens("/* private ", { });
	ExpectTokens("/*1private1", { });
	ExpectTokens("/*;private;", { });
}
