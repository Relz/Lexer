#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include "Constant.h"
#include "InputSolution/Input/Input.h"
#include <string>
#include <unordered_set>
#include <vector>

class TokenInformation;
enum class NumberSystem;
enum class Token;

class Lexer
{
public:
	explicit Lexer(std::string const & inputFileName);
	explicit Lexer(std::istream & is);
	bool GetNextTokenInformation(TokenInformation & tokenInformation);

private:
	static std::unordered_set<std::string> const DELIMITERS_TO_SKIP;

	std::string const m_inputFileName;
	Input m_input;
	std::vector<TokenInformation> m_tokenInformations;

	bool PopNextTokenInformation(TokenInformation & tokenInformation);
	bool DetermineNextTokenInformation(TokenInformation & tokenInformation);
	bool TryToSkipComment(std::string const & delimiterString);
	bool TryToCreateLiteral(std::string const & delimiterString, std::string & literal);
	bool NeedMoreScanning(std::string const & scannedString, std::string const & delimiter);
	void SkipBlockComment();
	static bool DetermineScannedStringToken(std::string const & scannedString, Token & token);
	static bool IsIdentifier(std::string const & str);
	static bool IsDigit(char ch, NumberSystem numberSystem = DEFAULT_NUMBER_SYSTEM);
	static bool IsInteger(
		std::string const & str,
		size_t fromIndex,
		size_t & failIndex,
		std::string & goodString,
		NumberSystem numberSystem = DEFAULT_NUMBER_SYSTEM);
	static bool DetermineNumberToken(std::string const & scannedString, Token & token);
	static bool DetermineDelimiterToken(std::string const & delimiterString, Token & token);
	static bool TryToAddLiteralToken(std::string const & delimiterString, Token & token);
};

#endif //LEXER_LEXER_H
