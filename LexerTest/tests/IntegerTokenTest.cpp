#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(integer_token, determining_if_stay_alone)
{
	ExpectTokens("1", { Token::INTEGER });
	ExpectTokens("2_1", { Token::INTEGER });
	ExpectTokens("16_F", { Token::INTEGER });
}

TEST(integer_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" 1 ", { Token::INTEGER });
	ExpectTokens(";1;", { Token::SEMICOLON, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(" 2_1 ", { Token::INTEGER });
	ExpectTokens(";2_1;", { Token::SEMICOLON, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(" 16_F ", { Token::INTEGER });
	ExpectTokens(";16_F;", { Token::SEMICOLON, Token::INTEGER, Token::SEMICOLON });
}

TEST(integer_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("1;", { Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(";1", { Token::SEMICOLON, Token::INTEGER });
	ExpectTokens(" 2_1;", { Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(";2_1", { Token::SEMICOLON, Token::INTEGER });
	ExpectTokens("16_F;", { Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(";16_F", { Token::SEMICOLON, Token::INTEGER });
}

TEST(integer_token, not_determining_if_not_completed)
{
	ExpectTokens("2_", { Token::UNKNOWN });
	ExpectTokens("16_", { Token::UNKNOWN });
}

TEST(integer_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";1;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"2_1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 2_1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";2_1;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"16_F\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 16_F \"", { Token::STRING_LITERAL });
	ExpectTokens("\";16_F;\"", { Token::STRING_LITERAL });
}

TEST(integer_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//1", { Token::LINE_COMMENT });
	ExpectTokens("// 1 ", { Token::LINE_COMMENT });
	ExpectTokens("//;1;", { Token::LINE_COMMENT });
	ExpectTokens("/*1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* 1 */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;1;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1", { Token::BLOCK_COMMENT });
	ExpectTokens("/* 1 ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;1;", { Token::BLOCK_COMMENT });

	ExpectTokens("//2_1", { Token::LINE_COMMENT });
	ExpectTokens("// 2_1 ", { Token::LINE_COMMENT });
	ExpectTokens("//;2_1;", { Token::LINE_COMMENT });
	ExpectTokens("/*2_1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* 2_1 */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*2_1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;2_1;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*2_1", { Token::BLOCK_COMMENT });
	ExpectTokens("/* 2_1 ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*2_1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;2_1;", { Token::BLOCK_COMMENT });

	ExpectTokens("//16_F", { Token::LINE_COMMENT });
	ExpectTokens("// 16_F ", { Token::LINE_COMMENT });
	ExpectTokens("//;16_F;", { Token::LINE_COMMENT });
	ExpectTokens("/*16_F*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* 16_F */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*16_F*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;16_F;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*16_F", { Token::BLOCK_COMMENT });
	ExpectTokens("/* 16_F ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*16_F", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;16_F;", { Token::BLOCK_COMMENT });
}
