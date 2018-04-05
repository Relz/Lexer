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

TEST(private_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1private1", { Token::UNKNOWN });
	ExpectTokens("1private1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1private1", { Token::UNKNOWN });
	ExpectTokens("1.1private1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1private1", { Token::UNKNOWN });
	ExpectTokens("1private1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
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
	ExpectTokens("//private", { Token::LINE_COMMENT });
	ExpectTokens("// private ", { Token::LINE_COMMENT });
	ExpectTokens("//1private1", { Token::LINE_COMMENT });
	ExpectTokens("//;private;", { Token::LINE_COMMENT });
	ExpectTokens("/*private*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* private */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1private1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;private;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*private", { Token::BLOCK_COMMENT });
	ExpectTokens("/* private ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1private1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;private;", { Token::BLOCK_COMMENT });
}
