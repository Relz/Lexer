#include "Lexer/Token/TokenInformation/TokenInformation.h"
#include "Lexer/Lexer.h"
#include "gtest/gtest.h"
#include "TestHelper.h"
#include <sstream>

void ExpectTokens(std::string const & str, std::vector<Token> const & expectedTokens)
{
	std::stringstream stringStream(str);
	Lexer lexer(stringStream);
	size_t i = 0;
	TokenInformation tokenInformation;
	while (lexer.GetNextTokenInformation(tokenInformation))
	{
		EXPECT_LT(i, expectedTokens.size());
		EXPECT_EQ(
			TokenExtensions::ToString(tokenInformation.GetToken()), TokenExtensions::ToString(expectedTokens.at(i)));
		++i;
	}
	EXPECT_EQ(i, expectedTokens.size());
}
