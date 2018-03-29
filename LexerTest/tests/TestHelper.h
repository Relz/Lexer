#ifndef PROJECT_TESTHELPER_H
#define PROJECT_TESTHELPER_H

#include <string>
#include <vector>

enum class Token;

void ExpectTokens(std::string const & str, std::vector<Token> const & expectedTokens);

#endif //PROJECT_TESTHELPER_H
