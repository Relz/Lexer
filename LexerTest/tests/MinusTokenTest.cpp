#include "TestHelper.h"

using namespace std;

TEST(minus_token, determining_if_stay_alone)
{
	ExpectTokens("-", { Token::MINUS });
}

TEST(minus_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" - ", { Token::MINUS });
	ExpectTokens(";-;", { Token::SEMICOLON, Token::MINUS, Token::SEMICOLON });
}

TEST(minus_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("-;", { Token::MINUS, Token::SEMICOLON });
	ExpectTokens(";-", { Token::SEMICOLON, Token::MINUS });
}

TEST(minus_token, determining_if_between_numbers)
{
	ExpectTokens("1-1", { Token::INTEGER, Token::MINUS, Token::INTEGER });
	ExpectTokens("1-1.1", { Token::INTEGER, Token::MINUS, Token::FLOAT });
	ExpectTokens("1.1-1", { Token::FLOAT, Token::MINUS, Token::INTEGER });
	ExpectTokens("1.1-1.1", { Token::FLOAT, Token::MINUS, Token::FLOAT });
	ExpectTokens("1E-1-1", { Token::EXPONENTIAL, Token::MINUS, Token::INTEGER });
	ExpectTokens("1-1E-1", { Token::INTEGER, Token::MINUS, Token::EXPONENTIAL });
	ExpectTokens("1.1E-1-1", { Token::EXPONENTIAL, Token::MINUS, Token::INTEGER });
	ExpectTokens("1-1.1E-1", { Token::INTEGER, Token::MINUS, Token::EXPONENTIAL });
	ExpectTokens("1E-1.1-1", { Token::EXPONENTIAL, Token::MINUS, Token::INTEGER });
	ExpectTokens("1-1E-1.1", { Token::INTEGER, Token::MINUS, Token::EXPONENTIAL });
	ExpectTokens("1E-1-1.1", { Token::EXPONENTIAL, Token::MINUS, Token::FLOAT });
	ExpectTokens("1.1-1E-1", { Token::FLOAT, Token::MINUS, Token::EXPONENTIAL });
	ExpectTokens("1E-1-1E-1", { Token::EXPONENTIAL, Token::MINUS, Token::EXPONENTIAL });
}

TEST(minus_token, not_determining_if_part_of_minus_assignment)
{
	ExpectTokens("-=", { Token::MINUS_ASSIGNMENT });
	ExpectTokens("--=", { Token::MINUS, Token::MINUS_ASSIGNMENT });
	ExpectTokens("-=-", { Token::MINUS_ASSIGNMENT, Token::MINUS });
}

TEST(minus_token, not_determining_if_in_character_literal)
{
	ExpectTokens("'-'", { Token::CHARACTER_LITERAL });
}

TEST(minus_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"-\"", { Token::STRING_LITERAL });
	ExpectTokens("\" - \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1-1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";-;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"---\"", { Token::STRING_LITERAL });
}

TEST(minus_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//-", {});
	ExpectTokens("// - ", {});
	ExpectTokens("//1-1", {});
	ExpectTokens("//;-;", {});
	ExpectTokens("//---", {});
	ExpectTokens("/*-*/", {});
	ExpectTokens("/* - */", {});
	ExpectTokens("/*1-1*/", {});
	ExpectTokens("/*;-;*/", {});
	ExpectTokens("/*---*/", {});
	ExpectTokens("/*-", {});
	ExpectTokens("/* - ", {});
	ExpectTokens("/*1-1", {});
	ExpectTokens("/*;-;", {});
	ExpectTokens("/*---", {});
}
