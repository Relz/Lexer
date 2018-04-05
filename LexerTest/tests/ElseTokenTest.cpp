#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(else_token, determining_if_stay_alone)
{
	ExpectTokens("else", { Token::ELSE });
}

TEST(else_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" else ", { Token::ELSE });
	ExpectTokens(";else;", { Token::SEMICOLON, Token::ELSE, Token::SEMICOLON });
}

TEST(else_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("else;", { Token::ELSE, Token::SEMICOLON });
	ExpectTokens(";else", { Token::SEMICOLON, Token::ELSE });
}

TEST(else_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1else1", { Token::UNKNOWN });
	ExpectTokens("1else1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1else1", { Token::UNKNOWN });
	ExpectTokens("1.1else1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1else1", { Token::UNKNOWN });
	ExpectTokens("1else1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(else_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"else\"", { Token::STRING_LITERAL });
	ExpectTokens("\" else \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1else1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";else;\"", { Token::STRING_LITERAL });
}

TEST(else_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//else", { Token::LINE_COMMENT });
	ExpectTokens("// else ", { Token::LINE_COMMENT });
	ExpectTokens("//1else1", { Token::LINE_COMMENT });
	ExpectTokens("//;else;", { Token::LINE_COMMENT });
	ExpectTokens("/*else*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* else */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1else1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;else;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*else", { Token::BLOCK_COMMENT });
	ExpectTokens("/* else ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1else1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;else;", { Token::BLOCK_COMMENT });
}
