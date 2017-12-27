#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "Constant.h"
#include "Input/Input.h"
#include "Token/TokenInfo.h"
#include "Token/TokenUtils.h"
#include "Constant.h"

class Lexer
{
public:
	explicit Lexer(const std::string & inputFileName);
	void Print();

private:
	bool Skip(const std::string & scannedString, const std::string & delimiter);
	bool NeedMoreScanning(const std::string & scannedString, const std::string & delimiter);
	void SkipBlockComment();

	CInput _input;
	const std::string _inputFileName;
	std::vector<TokenInfo> _tokenInfos;

	static const std::unordered_map<std::string, std::unordered_set<std::string>> SCANNER_SKIPS;
};

#endif //LEXER_LEXER_H
