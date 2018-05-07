#ifndef LEXER_NUMBERSYSTEMEXTENSIONS_H
#define LEXER_NUMBERSYSTEMEXTENSIONS_H

#include <set>
#include <unordered_map>

enum class NumberSystem;

class NumberSystemExtensions
{
public:
	static void CreateAvailableCharacters(NumberSystem numberSystem, std::set<wchar_t> & availableCharacters);
	static bool CreateFromString(std::wstring const & str, NumberSystem & numberSystem);
	static unsigned int ToUInt(NumberSystem numberSystem);

private:
	static NumberSystem const DEFAULT_NUMBER_SYSTEM;
	static std::set<wchar_t> const ALL_AVAILABLE_CHARACTERS;
	static std::set<wchar_t> const DEFAULT_NUMBER_SYSTEM_DIGITS;
	static std::unordered_map<std::wstring, NumberSystem> const STRING_TO_NUMBER_SYSTEM;
	static std::unordered_map<NumberSystem, unsigned int> const NUMBER_SYSTEM_TO_UINT;
};

#endif
