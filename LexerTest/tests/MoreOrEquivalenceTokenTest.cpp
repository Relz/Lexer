#include "TestHelper.h"

using namespace std;

TEST(more_or_equivalence_token, determining_if_stay_alone)
{
	ExpectTokens(">=", { Token::MORE_OR_EQUIVALENCE });
}

TEST(more_or_equivalence_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" >= ", { Token::MORE_OR_EQUIVALENCE });
	ExpectTokens(";>=;", { Token::SEMICOLON, Token::MORE_OR_EQUIVALENCE, Token::SEMICOLON });
}

TEST(more_or_equivalence_token, determining_if_stay_near_delimiter)
{
	ExpectTokens(">=;", { Token::MORE_OR_EQUIVALENCE, Token::SEMICOLON });
	ExpectTokens(";>=", { Token::SEMICOLON, Token::MORE_OR_EQUIVALENCE });
}

TEST(more_or_equivalence_token, determining_if_between_numbers)
{
	ExpectTokens("1>=1", { Token::INTEGER, Token::MORE_OR_EQUIVALENCE, Token::INTEGER });
	ExpectTokens("1>=1.1", { Token::INTEGER, Token::MORE_OR_EQUIVALENCE, Token::FLOAT });
	ExpectTokens("1.1>=1", { Token::FLOAT, Token::MORE_OR_EQUIVALENCE, Token::INTEGER });
	ExpectTokens("1.1>=1.1", { Token::FLOAT, Token::MORE_OR_EQUIVALENCE, Token::FLOAT });
	ExpectTokens("1E+1>=1", { Token::EXPONENTIAL, Token::MORE_OR_EQUIVALENCE, Token::INTEGER });
	ExpectTokens("1>=1E+1", { Token::INTEGER, Token::MORE_OR_EQUIVALENCE, Token::EXPONENTIAL });
}

TEST(more_or_equivalence_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\">=\"", { Token::STRING_LITERAL });
	ExpectTokens("\" >= \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1>=1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";>=;\"", { Token::STRING_LITERAL });
}

TEST(more_or_equivalence_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//>=", { });
	ExpectTokens("// >= ", { });
	ExpectTokens("//1>=1", { });
	ExpectTokens("//;>=;", { });
	ExpectTokens("/*>=*/", { });
	ExpectTokens("/* >= */", { });
	ExpectTokens("/*1>=1*/", { });
	ExpectTokens("/*;>=;*/", { });
	ExpectTokens("/*>=", { });
	ExpectTokens("/* >= ", { });
	ExpectTokens("/*1>=1", { });
	ExpectTokens("/*;>=;", { });
}
