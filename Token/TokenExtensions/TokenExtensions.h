#ifndef TOKEN_TOKENEXTENSIONS_H
#define TOKEN_TOKENEXTENSIONS_H

#include "../Constant/Constant.h"
#include "../Token.h"
#include <string>
#include <unordered_map>
#include <unordered_set>

class TokenExtensions
{
public:
	static bool TryToGetDelimiterToken(std::string const & str, Token & token);
	static bool TryToGetKeywordToken(std::string const & str, Token & token);
	static bool TryToGetTypeToken(
		std::string const & str, Token & token, std::unordered_set<std::string> const & customTypes);
	static std::string ToString(Token token);

private:
	static std::unordered_map<std::string, Token> const STRING_TO_DELIMITER_TOKEN;
	static std::unordered_map<std::string, Token> const STRING_TO_KEYWORD_TOKEN;
	static std::unordered_set<std::string> const TYPES;
	static std::unordered_map<Token, std::string> const TOKEN_TO_NAME;
};

#endif //TOKEN_TOKENEXTENSIONS_H
