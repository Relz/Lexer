#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(more_token, determining_if_stay_alone)
{
	ExpectTokens(">", { Token::MORE });
}

TEST(more_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" > ", { Token::MORE });
	ExpectTokens(";>;", { Token::SEMICOLON, Token::MORE, Token::SEMICOLON });
}

TEST(more_token, determining_if_stay_near_delimiter)
{
	ExpectTokens(">;", { Token::MORE, Token::SEMICOLON });
	ExpectTokens(";>", { Token::SEMICOLON, Token::MORE });
}

TEST(more_token, determining_if_stay_between_numbers)
{
	ExpectTokens("1>1", { Token::INTEGER, Token::MORE, Token::INTEGER });
	ExpectTokens("1>1.1", { Token::INTEGER, Token::MORE, Token::FLOAT });
	ExpectTokens("1.1>1", { Token::FLOAT, Token::MORE, Token::INTEGER });
	ExpectTokens("1.1>1.1", { Token::FLOAT, Token::MORE, Token::FLOAT });
	ExpectTokens("1_E+1>1", { Token::EXPONENTIAL, Token::MORE, Token::INTEGER });
	ExpectTokens("1>1_E+1", { Token::INTEGER, Token::MORE, Token::EXPONENTIAL });
}

TEST(more_token, not_determining_if_in_character_literal)
{
	ExpectTokens("'>'", { Token::CHARACTER_LITERAL });
}

TEST(more_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\">\"", { Token::STRING_LITERAL });
	ExpectTokens("\" > \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1>1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";>;\"", { Token::STRING_LITERAL });
}

TEST(more_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//>", { Token::LINE_COMMENT });
	ExpectTokens("// > ", { Token::LINE_COMMENT });
	ExpectTokens("//1>1", { Token::LINE_COMMENT });
	ExpectTokens("//;>;", { Token::LINE_COMMENT });
	ExpectTokens("/*>*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* > */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1>1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;>;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*>", { Token::BLOCK_COMMENT });
	ExpectTokens("/* > ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1>1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;>;", { Token::BLOCK_COMMENT });
}
