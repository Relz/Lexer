#ifndef TOKEN_TOKENEXTENSIONS_H
#define TOKEN_TOKENEXTENSIONS_H

#include "../TokenConstant/TokenConstant.h"
#include "../Token.h"
#include <string>
#include <unordered_map>
#include <unordered_set>

class TokenExtensions
{
public:
	static bool TryToGetDelimiterToken(std::wstring const & str, Token & token);
	static bool TryToGetKeywordToken(std::wstring const & str, Token & token);
	static bool TryToGetTypeToken(
		std::wstring const & str, Token & token, std::unordered_set<std::wstring> const & customTypes);
	static std::wstring ToString(Token token);

private:
	static std::unordered_map<std::wstring, Token> const STRING_TO_DELIMITER_TOKEN;
	static std::unordered_map<std::wstring, Token> const STRING_TO_KEYWORD_TOKEN;
	static std::unordered_set<std::wstring> const TYPES;
	static std::unordered_map<Token, std::wstring> const TOKEN_TO_NAME;
};

#endif
