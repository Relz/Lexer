#include "NumberSystemExtensions.h"
#include "../NumberSystem.h"

void NumberSystemExtensions::CreateAvailableCharacters(NumberSystem numberSystem, std::set<wchar_t> & availableCharacters)
{
	if (numberSystem == DEFAULT_NUMBER_SYSTEM)
	{
		availableCharacters = DEFAULT_NUMBER_SYSTEM_DIGITS;
		return;
	}
	auto goalIterator = ALL_AVAILABLE_CHARACTERS.begin();
	std::advance(goalIterator, ToUInt(numberSystem));
	availableCharacters = std::set<wchar_t>(ALL_AVAILABLE_CHARACTERS.begin(), goalIterator);
}

bool NumberSystemExtensions::CreateFromString(std::wstring const & str, NumberSystem & numberSystem)
{
	if (STRING_TO_NUMBER_SYSTEM.find(str) == STRING_TO_NUMBER_SYSTEM.end())
	{
		return false;
	}
	numberSystem = STRING_TO_NUMBER_SYSTEM.at(str);
	return true;
}

unsigned int NumberSystemExtensions::ToUInt(NumberSystem numberSystem)
{
	return NUMBER_SYSTEM_TO_UINT.at(numberSystem);
}

NumberSystem const NumberSystemExtensions::DEFAULT_NUMBER_SYSTEM = NumberSystem::TEN;

std::set<wchar_t> const NumberSystemExtensions::ALL_AVAILABLE_CHARACTERS {
	L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'A', L'B', L'C', L'D', L'E', L'F'
};

std::set<wchar_t> const NumberSystemExtensions::DEFAULT_NUMBER_SYSTEM_DIGITS {
	L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9'
};

std::unordered_map<std::wstring, NumberSystem> const NumberSystemExtensions::STRING_TO_NUMBER_SYSTEM {
	{ L"2", NumberSystem::TWO },
	{ L"3", NumberSystem::THREE },
	{ L"4", NumberSystem::FOUR },
	{ L"5", NumberSystem::FIVE },
	{ L"6", NumberSystem::SIX },
	{ L"7", NumberSystem::SEVEN },
	{ L"8", NumberSystem::EIGHT },
	{ L"9", NumberSystem::NINE },
	{ L"10", NumberSystem::TEN },
	{ L"11", NumberSystem::ELEVEN },
	{ L"12", NumberSystem::TWELVE },
	{ L"13", NumberSystem::THIRTEEN },
	{ L"14", NumberSystem::FOURTEEN },
	{ L"15", NumberSystem::FIFTEEN },
	{ L"16", NumberSystem::SIXTEEN }
};

std::unordered_map<NumberSystem, unsigned int> const NumberSystemExtensions::NUMBER_SYSTEM_TO_UINT {
	{ NumberSystem::TWO, 2 },
	{ NumberSystem::THREE, 3 },
	{ NumberSystem::FOUR, 4 },
	{ NumberSystem::FIVE, 5 },
	{ NumberSystem::SIX, 6 },
	{ NumberSystem::SEVEN, 7 },
	{ NumberSystem::EIGHT, 8 },
	{ NumberSystem::NINE, 9 },
	{ NumberSystem::TEN, 10 },
	{ NumberSystem::ELEVEN, 11 },
	{ NumberSystem::TWELVE, 12 },
	{ NumberSystem::THIRTEEN, 13 },
	{ NumberSystem::FOURTEEN, 14 },
	{ NumberSystem::FIFTEEN, 15 },
	{ NumberSystem::SIXTEEN, 16 }
};
