#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(not_equivalence_token, determining_if_stay_alone)
{
	ExpectTokens("!=", { Token::EQUIVALENCE });
}

TEST(not_equivalence_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" != ", { Token::EQUIVALENCE });
	ExpectTokens(";!=;", { Token::SEMICOLON, Token::EQUIVALENCE, Token::SEMICOLON });
}

TEST(not_equivalence_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("!=;", { Token::EQUIVALENCE, Token::SEMICOLON });
	ExpectTokens(";!=", { Token::SEMICOLON, Token::EQUIVALENCE });
}

TEST(not_equivalence_token, determining_if_between_numbers)
{
	ExpectTokens("1!=1", { Token::INTEGER, Token::EQUIVALENCE, Token::INTEGER });
	ExpectTokens("1!=1.1", { Token::INTEGER, Token::EQUIVALENCE, Token::FLOAT });
	ExpectTokens("1.1!=1", { Token::FLOAT, Token::EQUIVALENCE, Token::INTEGER });
	ExpectTokens("1.1!=1.1", { Token::FLOAT, Token::EQUIVALENCE, Token::FLOAT });
	ExpectTokens("1E+1!=1", { Token::EXPONENTIAL, Token::EQUIVALENCE, Token::INTEGER });
	ExpectTokens("1!=1E+1", { Token::INTEGER, Token::EQUIVALENCE, Token::EXPONENTIAL });
}

TEST(not_equivalence_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"!=\"", { Token::STRING_LITERAL });
	ExpectTokens("\" != \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1!=1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";!=;\"", { Token::STRING_LITERAL });
}

TEST(not_equivalence_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//!=", { });
	ExpectTokens("// != ", { });
	ExpectTokens("//1!=1", { });
	ExpectTokens("//;!=;", { });
	ExpectTokens("/*!=*/", { });
	ExpectTokens("/* != */", { });
	ExpectTokens("/*1!=1*/", { });
	ExpectTokens("/*;!=;*/", { });
	ExpectTokens("/*!=", { });
	ExpectTokens("/* != ", { });
	ExpectTokens("/*1!=1", { });
	ExpectTokens("/*;!=;", { });
}
