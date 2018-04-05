#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(character_literal_token, determining_if_stay_alone)
{
	ExpectTokens(R"('a')", { Token::CHARACTER_LITERAL });
	ExpectTokens(R"('_')", { Token::CHARACTER_LITERAL });
	ExpectTokens(R"('b''c')", { Token::CHARACTER_LITERAL, Token::CHARACTER_LITERAL });
}

TEST(character_literal_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(R"( '1' )", { Token::CHARACTER_LITERAL });
	ExpectTokens(R"(;'1';)", { Token::SEMICOLON, Token::CHARACTER_LITERAL, Token::SEMICOLON });
}

TEST(character_literal_token, determining_if_stay_near_delimiter)
{
	ExpectTokens(R"('1';)", { Token::CHARACTER_LITERAL, Token::SEMICOLON });
	ExpectTokens(R"(;'1')", { Token::SEMICOLON, Token::CHARACTER_LITERAL });
}

TEST(character_literal_token, determining_if_stay_between_numbers)
{
	ExpectTokens(R"(1'1'1)", { Token::INTEGER, Token::CHARACTER_LITERAL, Token::INTEGER });
	ExpectTokens(R"(1'1'1.1)", { Token::INTEGER, Token::CHARACTER_LITERAL, Token::FLOAT });
	ExpectTokens(R"(1.1'1'1)", { Token::FLOAT, Token::CHARACTER_LITERAL, Token::INTEGER });
	ExpectTokens(R"(1.1'1'1.1)", { Token::FLOAT, Token::CHARACTER_LITERAL, Token::FLOAT });
	ExpectTokens(R"(1_E+1'1'1)", { Token::EXPONENTIAL, Token::CHARACTER_LITERAL, Token::INTEGER });
	ExpectTokens(R"(1'1'1_E+1)", { Token::INTEGER, Token::CHARACTER_LITERAL, Token::EXPONENTIAL });
}

TEST(character_literal_token, not_determining_if_has_length_not_equal_to_one)
{
	ExpectTokens(R"('')", { Token::UNKNOWN });
	ExpectTokens(R"('11')", { Token::UNKNOWN });
}

TEST(character_literal_token, not_determining_if_part_of_comment)
{
	ExpectTokens(R"(//'1')", { Token::LINE_COMMENT });
	ExpectTokens(R"(// '1' )", { Token::LINE_COMMENT });
	ExpectTokens(R"(//1'1'1)", { Token::LINE_COMMENT });
	ExpectTokens(R"(//;'1';)", { Token::LINE_COMMENT });
	ExpectTokens(R"(/*'1'*/)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/* '1' */)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*1'1'1*/)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*;'1';*/)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*'1')", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/* '1' )", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*1'1'1)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*;'1';)", { Token::BLOCK_COMMENT });
}
