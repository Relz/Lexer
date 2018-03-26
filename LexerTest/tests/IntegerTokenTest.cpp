#include "TestHelper.h"

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
	ExpectTokens("//1", {});
	ExpectTokens("// 1 ", {});
	ExpectTokens("//;1;", {});
	ExpectTokens("/*1*/", {});
	ExpectTokens("/* 1 */", {});
	ExpectTokens("/*1*/", {});
	ExpectTokens("/*;1;*/", {});
	ExpectTokens("/*1", {});
	ExpectTokens("/* 1 ", {});
	ExpectTokens("/*1", {});
	ExpectTokens("/*;1;", {});

	ExpectTokens("//2_1", {});
	ExpectTokens("// 2_1 ", {});
	ExpectTokens("//;2_1;", {});
	ExpectTokens("/*2_1*/", {});
	ExpectTokens("/* 2_1 */", {});
	ExpectTokens("/*2_1*/", {});
	ExpectTokens("/*;2_1;*/", {});
	ExpectTokens("/*2_1", {});
	ExpectTokens("/* 2_1 ", {});
	ExpectTokens("/*2_1", {});
	ExpectTokens("/*;2_1;", {});

	ExpectTokens("//16_F", {});
	ExpectTokens("// 16_F ", {});
	ExpectTokens("//;16_F;", {});
	ExpectTokens("/*16_F*/", {});
	ExpectTokens("/* 16_F */", {});
	ExpectTokens("/*16_F*/", {});
	ExpectTokens("/*;16_F;*/", {});
	ExpectTokens("/*16_F", {});
	ExpectTokens("/* 16_F ", {});
	ExpectTokens("/*16_F", {});
	ExpectTokens("/*;16_F;", {});
}
