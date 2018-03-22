#include "gtest/gtest.h"
#include <string>
#include <sstream>

#include "TestHelper.h"

using namespace std;

TEST(minus_token, determining_if_stay_alone)
{
	test("-", { Token::MINUS });
}

TEST(minus_token, determining_if_stay_between_delimiters)
{
	test(" - ", { Token::MINUS });
	test(";-;", { Token::SEMICOLON, Token::MINUS, Token::SEMICOLON });
}

TEST(minus_token, determining_if_stay_near_delimiter)
{
	test("-;", { Token::MINUS, Token::SEMICOLON });
	test(";-", { Token::SEMICOLON, Token::MINUS });
}

TEST(minus_token, determining_if_between_numbers)
{
	test("1-1", { Token::INTEGER, Token::MINUS, Token::INTEGER });
	test("1-1.1", { Token::INTEGER, Token::MINUS, Token::FLOAT });
	test("1.1-1", { Token::FLOAT, Token::MINUS, Token::INTEGER });
	test("1.1-1.1", { Token::FLOAT, Token::MINUS, Token::FLOAT });
	test("1E-1-1", { Token::EXPONENTIAL, Token::MINUS, Token::INTEGER });
	test("1-1E-1", { Token::INTEGER, Token::MINUS, Token::EXPONENTIAL });
	test("1.1E-1-1", { Token::EXPONENTIAL, Token::MINUS, Token::INTEGER });
	test("1-1.1E-1", { Token::INTEGER, Token::MINUS, Token::EXPONENTIAL });
	test("1E-1.1-1", { Token::EXPONENTIAL, Token::MINUS, Token::INTEGER });
	test("1-1E-1.1", { Token::INTEGER, Token::MINUS, Token::EXPONENTIAL });
	test("1E-1-1.1", { Token::EXPONENTIAL, Token::MINUS, Token::FLOAT });
	test("1.1-1E-1", { Token::FLOAT, Token::MINUS, Token::EXPONENTIAL });
	test("1E-1-1E-1", { Token::EXPONENTIAL, Token::MINUS, Token::EXPONENTIAL });
}
