#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(implements_token, determining_if_stay_alone)
{
	ExpectTokens("implements", { Token::IMPLEMENTS });
}

TEST(implements_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" implements ", { Token::IMPLEMENTS });
	ExpectTokens(";implements;", { Token::SEMICOLON, Token::IMPLEMENTS, Token::SEMICOLON });
}

TEST(implements_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("implements;", { Token::IMPLEMENTS, Token::SEMICOLON });
	ExpectTokens(";implements", { Token::SEMICOLON, Token::IMPLEMENTS });
}

TEST(implements_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1implements1", { Token::UNKNOWN });
	ExpectTokens("1implements1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1implements1", { Token::UNKNOWN });
	ExpectTokens("1.1implements1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1implements1", { Token::UNKNOWN });
	ExpectTokens("1implements1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(implements_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"implements\"", { Token::STRING_LITERAL });
	ExpectTokens("\" implements \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1implements1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";implements;\"", { Token::STRING_LITERAL });
}

TEST(implements_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//implements", { });
	ExpectTokens("// implements ", { });
	ExpectTokens("//1implements1", { });
	ExpectTokens("//;implements;", { });
	ExpectTokens("/*implements*/", { });
	ExpectTokens("/* implements */", { });
	ExpectTokens("/*1implements1*/", { });
	ExpectTokens("/*;implements;*/", { });
	ExpectTokens("/*implements", { });
	ExpectTokens("/* implements ", { });
	ExpectTokens("/*1implements1", { });
	ExpectTokens("/*;implements;", { });
}
