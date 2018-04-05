#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

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

TEST(get_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1get1", { Token::UNKNOWN });
	ExpectTokens("1get1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1get1", { Token::UNKNOWN });
	ExpectTokens("1.1get1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1get1", { Token::UNKNOWN });
	ExpectTokens("1get1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
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
	ExpectTokens("//get", { Token::LINE_COMMENT });
	ExpectTokens("// get ", { Token::LINE_COMMENT });
	ExpectTokens("//1get1", { Token::LINE_COMMENT });
	ExpectTokens("//;get;", { Token::LINE_COMMENT });
	ExpectTokens("/*get*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* get */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1get1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;get;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*get", { Token::BLOCK_COMMENT });
	ExpectTokens("/* get ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1get1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;get;", { Token::BLOCK_COMMENT });
}
