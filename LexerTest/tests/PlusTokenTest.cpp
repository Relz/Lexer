#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(plus_token, determining_if_stay_alone)
{
	ExpectTokens("+", { Token::PLUS });
}

TEST(plus_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" + ", { Token::PLUS });
	ExpectTokens(";+;", { Token::SEMICOLON, Token::PLUS, Token::SEMICOLON });
}

TEST(plus_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("+;", { Token::PLUS, Token::SEMICOLON });
	ExpectTokens(";+", { Token::SEMICOLON, Token::PLUS });
}

TEST(plus_token, determining_if_stay_between_numbers)
{
	ExpectTokens("1+1", { Token::INTEGER, Token::PLUS, Token::INTEGER });
	ExpectTokens("1+1.1", { Token::INTEGER, Token::PLUS, Token::FLOAT });
	ExpectTokens("1.1+1", { Token::FLOAT, Token::PLUS, Token::INTEGER });
	ExpectTokens("1.1+1.1", { Token::FLOAT, Token::PLUS, Token::FLOAT });
	ExpectTokens("1_E+1+1", { Token::EXPONENTIAL, Token::PLUS, Token::INTEGER });
	ExpectTokens("1+1_E+1", { Token::INTEGER, Token::PLUS, Token::EXPONENTIAL });
	ExpectTokens("1.1_E+1+1", { Token::EXPONENTIAL, Token::PLUS, Token::INTEGER });
	ExpectTokens("1+1.1_E+1", { Token::INTEGER, Token::PLUS, Token::EXPONENTIAL });
	ExpectTokens("1_E+1.1+1", { Token::EXPONENTIAL, Token::PLUS, Token::INTEGER });
	ExpectTokens("1+1_E+1.1", { Token::INTEGER, Token::PLUS, Token::EXPONENTIAL });
	ExpectTokens("1_E+1+1.1", { Token::EXPONENTIAL, Token::PLUS, Token::FLOAT });
	ExpectTokens("1.1+1_E+1", { Token::FLOAT, Token::PLUS, Token::EXPONENTIAL });
	ExpectTokens("1_E+1+1_E+1", { Token::EXPONENTIAL, Token::PLUS, Token::EXPONENTIAL });
}

TEST(plus_token, not_determining_if_part_of_plus_assignment)
{
	ExpectTokens("+=", { Token::PLUS_ASSIGNMENT });
	ExpectTokens("++=", { Token::PLUS, Token::PLUS_ASSIGNMENT });
	ExpectTokens("+=+", { Token::PLUS_ASSIGNMENT, Token::PLUS });
}

TEST(plus_token, not_determining_if_in_character_literal)
{
	ExpectTokens("'+'", { Token::CHARACTER_LITERAL });
}

TEST(plus_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"+\"", { Token::STRING_LITERAL });
	ExpectTokens("\" + \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1+1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";+;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"+++\"", { Token::STRING_LITERAL });
}

TEST(plus_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//+", { Token::LINE_COMMENT });
	ExpectTokens("// + ", { Token::LINE_COMMENT });
	ExpectTokens("//1+1", { Token::LINE_COMMENT });
	ExpectTokens("//;+;", { Token::LINE_COMMENT });
	ExpectTokens("//+++", { Token::LINE_COMMENT });
	ExpectTokens("/*+*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* + */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1+1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;+;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*+++*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*+", { Token::BLOCK_COMMENT });
	ExpectTokens("/* + ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1+1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;+;", { Token::BLOCK_COMMENT });
	ExpectTokens("/*+++", { Token::BLOCK_COMMENT });
}
