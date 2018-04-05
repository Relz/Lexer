#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(string_literal_token, determining_if_stay_alone)
{
	ExpectTokens(R"("")", { Token::STRING_LITERAL });
	ExpectTokens(R"("_")", { Token::STRING_LITERAL });
	ExpectTokens(R"("""")", { Token::STRING_LITERAL, Token::STRING_LITERAL });
	ExpectTokens(R"("_id")", { Token::STRING_LITERAL });
}

TEST(string_literal_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(R"( "" )", { Token::STRING_LITERAL });
	ExpectTokens(R"(;"";)", { Token::SEMICOLON, Token::STRING_LITERAL, Token::SEMICOLON });
}

TEST(string_literal_token, determining_if_stay_near_delimiter)
{
	ExpectTokens(R"("";)", { Token::STRING_LITERAL, Token::SEMICOLON });
	ExpectTokens(R"(;"")", { Token::SEMICOLON, Token::STRING_LITERAL });
}

TEST(string_literal_token, determining_if_stay_between_numbers)
{
	ExpectTokens(R"(1""1)", { Token::INTEGER, Token::STRING_LITERAL, Token::INTEGER });
	ExpectTokens(R"(1""1.1)", { Token::INTEGER, Token::STRING_LITERAL, Token::FLOAT });
	ExpectTokens(R"(1.1""1)", { Token::FLOAT, Token::STRING_LITERAL, Token::INTEGER });
	ExpectTokens(R"(1.1""1.1)", { Token::FLOAT, Token::STRING_LITERAL, Token::FLOAT });
	ExpectTokens(R"(1_E+1""1)", { Token::EXPONENTIAL, Token::STRING_LITERAL, Token::INTEGER });
	ExpectTokens(R"(1""1_E+1)", { Token::INTEGER, Token::STRING_LITERAL, Token::EXPONENTIAL });
}

TEST(string_literal_token, not_determining_if_part_of_comment)
{
	ExpectTokens(R"(//"")", { Token::LINE_COMMENT });
	ExpectTokens(R"(// "" )", { Token::LINE_COMMENT });
	ExpectTokens(R"(//1""1)", { Token::LINE_COMMENT });
	ExpectTokens(R"(//;"";)", { Token::LINE_COMMENT });
	ExpectTokens(R"(/*""*/)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/* "" */)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*1""1*/)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*;"";*/)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*"")", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/* "" )", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*1""1)", { Token::BLOCK_COMMENT });
	ExpectTokens(R"(/*;"";)", { Token::BLOCK_COMMENT });
}
