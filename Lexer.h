#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include "InputLibrary/Input.h"
#include "NumberSystem/NumberSystem.h"
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
	explicit Lexer(std::wistream & is);
	bool GetNextTokenInformation(TokenInformation & tokenInformation);

private:
	static std::vector<std::wstring> const SCANNER_DELIMITERS;
	static NumberSystem const DEFAULT_NUMBER_SYSTEM;
	static std::unordered_set<std::wstring> const DELIMITERS_TO_SKIP;

	static bool DetermineScannedStringToken(
		std::wstring const & scannedString, Token & token, std::unordered_set<std::wstring> const & customTypes
	);
	static bool IsIdentifier(std::wstring const & str);
	static bool IsDigit(wchar_t ch, NumberSystem numberSystem = DEFAULT_NUMBER_SYSTEM);
	static bool IsInteger(
			std::wstring const & str,
			size_t fromIndex,
			size_t & failIndex,
			std::wstring & goodString,
			NumberSystem numberSystem = DEFAULT_NUMBER_SYSTEM
	);
	static bool DetermineNumberToken(std::wstring const & scannedString, Token & token);
	static bool DetermineDelimiterToken(std::wstring const & delimiterString, Token & token);
	static bool TryToAddLiteralToken(std::wstring const & delimiterString, Token & token);
	static bool TryToAddCommentToken(std::wstring const & delimiterString, Token & token);

	Input m_input;
	std::vector<TokenInformation> m_tokenInformations;
	std::unordered_set<std::wstring> m_customTypes;

	bool PopNextTokenInformation(TokenInformation & tokenInformation);
	bool DetermineNextTokenInformation(TokenInformation & tokenInformation);
	bool TryToCreateComment(std::wstring const & delimiterString, std::wstring & comment);
	bool TryToCreateLiteral(std::wstring const & delimiterString, std::wstring & literal);
	bool NeedMoreScanning(std::wstring const & scannedString, std::wstring const & delimiter);
};

#endif
