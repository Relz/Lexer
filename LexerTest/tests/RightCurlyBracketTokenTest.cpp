#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(right_curly_bracket_token, determining_if_stay_alone)
{
	ExpectTokens("}", { Token::RIGHT_CURLY_BRACKET });
}

TEST(right_curly_bracket_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" } ", { Token::RIGHT_CURLY_BRACKET });
	ExpectTokens(";};", { Token::SEMICOLON, Token::RIGHT_CURLY_BRACKET, Token::SEMICOLON });
}

TEST(right_curly_bracket_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("};", { Token::RIGHT_CURLY_BRACKET, Token::SEMICOLON });
	ExpectTokens(";}", { Token::SEMICOLON, Token::RIGHT_CURLY_BRACKET });
}

TEST(right_curly_bracket_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1}1", { Token::INTEGER, Token::RIGHT_CURLY_BRACKET, Token::INTEGER });
	ExpectTokens("1.1}1", { Token::FLOAT, Token::RIGHT_CURLY_BRACKET, Token::INTEGER });
	ExpectTokens("1}1.1", { Token::INTEGER, Token::RIGHT_CURLY_BRACKET, Token::FLOAT });
	ExpectTokens("1_E+1}1", { Token::EXPONENTIAL, Token::RIGHT_CURLY_BRACKET, Token::INTEGER });
	ExpectTokens("1}1_E+1", { Token::INTEGER, Token::RIGHT_CURLY_BRACKET, Token::EXPONENTIAL });
}

TEST(right_curly_bracket_token, not_determining_if_in_character_literal)
{
	ExpectTokens("'}'", { Token::CHARACTER_LITERAL });
}

TEST(right_curly_bracket_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"}\"", { Token::STRING_LITERAL });
	ExpectTokens("\" } \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1}1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";};\"", { Token::STRING_LITERAL });
}

TEST(right_curly_bracket_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//}", { Token::LINE_COMMENT });
	ExpectTokens("// } ", { Token::LINE_COMMENT });
	ExpectTokens("//1}1", { Token::LINE_COMMENT });
	ExpectTokens("//;};", { Token::LINE_COMMENT });
	ExpectTokens("/*}*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* } */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1}1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;};*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*}", { Token::BLOCK_COMMENT });
	ExpectTokens("/* } ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1}1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;};", { Token::BLOCK_COMMENT });
}
