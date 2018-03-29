#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(float_token, determining_if_stay_alone)
{
	ExpectTokens("1.1", { Token::FLOAT });
	ExpectTokens("2_1.1", { Token::FLOAT });
	ExpectTokens("16_F.A", { Token::FLOAT });
}

TEST(float_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" 1.1 ", { Token::FLOAT });
	ExpectTokens(";1.1;", { Token::SEMICOLON, Token::FLOAT, Token::SEMICOLON });
	ExpectTokens(" 2_1.1 ", { Token::FLOAT });
	ExpectTokens(";2_1.1;", { Token::SEMICOLON, Token::FLOAT, Token::SEMICOLON });
	ExpectTokens(" 16_F.A ", { Token::FLOAT });
	ExpectTokens(";16_F.A;", { Token::SEMICOLON, Token::FLOAT, Token::SEMICOLON });
}

TEST(float_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("1.1;", { Token::FLOAT, Token::SEMICOLON });
	ExpectTokens(";1.1", { Token::SEMICOLON, Token::FLOAT });
	ExpectTokens(" 2_1.1;", { Token::FLOAT, Token::SEMICOLON });
	ExpectTokens(";2_1.1", { Token::SEMICOLON, Token::FLOAT });
	ExpectTokens("16_F.A;", { Token::FLOAT, Token::SEMICOLON });
	ExpectTokens(";16_F.A", { Token::SEMICOLON, Token::FLOAT });
}

TEST(float_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"1.1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 1.1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";1.1;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"2_1.1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 2_1.1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";2_1.1;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"16_F.A\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 16_F.A \"", { Token::STRING_LITERAL });
	ExpectTokens("\";16_F.A;\"", { Token::STRING_LITERAL });
}

TEST(float_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//1.1", {});
	ExpectTokens("// 1.1 ", {});
	ExpectTokens("//;1.1;", {});
	ExpectTokens("/*1.1*/", {});
	ExpectTokens("/* 1.1 */", {});
	ExpectTokens("/*1.1*/", {});
	ExpectTokens("/*;1.1;*/", {});
	ExpectTokens("/*1.1", {});
	ExpectTokens("/* 1.1 ", {});
	ExpectTokens("/*1.1", {});
	ExpectTokens("/*;1.1;", {});

	ExpectTokens("//2_1.1", {});
	ExpectTokens("// 2_1.1 ", {});
	ExpectTokens("//;2_1.1;", {});
	ExpectTokens("/*2_1.1*/", {});
	ExpectTokens("/* 2_1.1 */", {});
	ExpectTokens("/*2_1.1*/", {});
	ExpectTokens("/*;2_1.1;*/", {});
	ExpectTokens("/*2_1.1", {});
	ExpectTokens("/* 2_1.1 ", {});
	ExpectTokens("/*2_1.1", {});
	ExpectTokens("/*;2_1.1;", {});

	ExpectTokens("//16_F.A", {});
	ExpectTokens("// 16_F.A ", {});
	ExpectTokens("//;16_F.A;", {});
	ExpectTokens("/*16_F.A*/", {});
	ExpectTokens("/* 16_F.A */", {});
	ExpectTokens("/*16_F.A*/", {});
	ExpectTokens("/*;16_F.A;*/", {});
	ExpectTokens("/*16_F.A", {});
	ExpectTokens("/* 16_F.A ", {});
	ExpectTokens("/*16_F.A", {});
	ExpectTokens("/*;16_F.A;", {});
}
