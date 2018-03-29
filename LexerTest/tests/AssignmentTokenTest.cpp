#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(assignment_token, determining_if_stay_alone)
{
	ExpectTokens("=", { Token::ASSIGNMENT });
}

TEST(assignment_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" = ", { Token::ASSIGNMENT });
	ExpectTokens(";=;", { Token::SEMICOLON, Token::ASSIGNMENT, Token::SEMICOLON });
}

TEST(assignment_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("=;", { Token::ASSIGNMENT, Token::SEMICOLON });
	ExpectTokens(";=", { Token::SEMICOLON, Token::ASSIGNMENT });
}

TEST(assignment_token, determining_if_between_numbers)
{
	ExpectTokens("1=1", { Token::INTEGER, Token::ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1=1.1", { Token::INTEGER, Token::ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1.1=1", { Token::FLOAT, Token::ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1.1=1.1", { Token::FLOAT, Token::ASSIGNMENT, Token::FLOAT });
	ExpectTokens("1E+1=1", { Token::EXPONENTIAL, Token::ASSIGNMENT, Token::INTEGER });
	ExpectTokens("1=1E+1", { Token::INTEGER, Token::ASSIGNMENT, Token::EXPONENTIAL });
}

TEST(assignment_token, not_determining_if_part_of_plus_assignment)
{
	ExpectTokens("+=", { Token::PLUS_ASSIGNMENT });
	ExpectTokens("=+=", { Token::ASSIGNMENT, Token::PLUS_ASSIGNMENT });
	ExpectTokens("+==", { Token::PLUS_ASSIGNMENT, Token::ASSIGNMENT });
}

TEST(assignment_token, not_determining_if_part_of_equivalence)
{
	ExpectTokens("==", { Token::EQUIVALENCE });
	ExpectTokens("===", { Token::EQUIVALENCE, Token::ASSIGNMENT });
}

TEST(assignment_token, not_determining_if_part_of_minus_assignment)
{
	ExpectTokens("-=", { Token::MINUS_ASSIGNMENT });
	ExpectTokens("=-=", { Token::ASSIGNMENT, Token::MINUS_ASSIGNMENT });
	ExpectTokens("-==", { Token::MINUS_ASSIGNMENT, Token::ASSIGNMENT });
}

TEST(assignment_token, not_determining_if_part_of_multiply_assignment)
{
	ExpectTokens("*=", { Token::MULTIPLY_ASSIGNMENT });
	ExpectTokens("=*=", { Token::ASSIGNMENT, Token::MULTIPLY_ASSIGNMENT });
	ExpectTokens("*==", { Token::MULTIPLY_ASSIGNMENT, Token::ASSIGNMENT });
}

TEST(assignment_token, not_determining_if_part_of_division_assignment)
{
	ExpectTokens("/=", { Token::DIVISION_ASSIGNMENT });
	ExpectTokens("=/=", { Token::ASSIGNMENT, Token::DIVISION_ASSIGNMENT });
	ExpectTokens("/==", { Token::DIVISION_ASSIGNMENT, Token::ASSIGNMENT });
}

TEST(assignment_token, not_determining_if_in_character_literal)
{
	ExpectTokens("'='", { Token::CHARACTER_LITERAL });
}

TEST(assignment_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"=\"", { Token::STRING_LITERAL });
	ExpectTokens("\" = \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1=1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";=;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"===\"", { Token::STRING_LITERAL });
}

TEST(assignment_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//=", { });
	ExpectTokens("// = ", { });
	ExpectTokens("//1=1", { });
	ExpectTokens("//;=;", { });
	ExpectTokens("//=", { });
	ExpectTokens("/*=*/", { });
	ExpectTokens("/* = */", { });
	ExpectTokens("/*1=1*/", { });
	ExpectTokens("/*;=;*/", { });
	ExpectTokens("/*=", { });
	ExpectTokens("/* = ", { });
	ExpectTokens("/*1=1", { });
	ExpectTokens("/*;=;", { });
}
