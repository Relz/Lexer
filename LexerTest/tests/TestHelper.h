#ifndef PROJECT_TESTHELPER_H
#define PROJECT_TESTHELPER_H

#include "Lexer/Lexer.h"
#include "Lexer/Token/Token.h"
#include "sstream"
#include "gtest/gtest.h"
#include <string>
#include <vector>

using namespace std;

void ExpectTokens(string const & string, vector<Token> const & expectedTokens);

#endif //PROJECT_TESTHELPER_H
