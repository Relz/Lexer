#ifndef TOKEN_RULE_H
#define TOKEN_RULE_H

#include <set>

namespace
{
	class Rule
	{
	public:
		static bool IsLetter(char ch)
		{
			return _UPPERCASE_LETTERS.find(ch) != _UPPERCASE_LETTERS.end()
					|| _LOWERCASE_LETTERS.find(ch) != _LOWERCASE_LETTERS.end();
		}

		static bool IsIdentifier(const std::string & str)
		{
			if (
					str.empty()
					|| (
						!IsLetter(str.front())
						&& !IsIdentifierSpecialCharacter(str.front())
					)
			)
			{
				return false;
			}
			bool result = true;
			for (size_t i = 1; i < str.length(); ++i)
			{
				if (
						!Rule::IsLetter(str.at(i))
						&& !Rule::IsDigit(str.at(i))
						&& !IsIdentifierSpecialCharacter(str.front())
				)
				{
					result = false;
					break;
				}
			}

			return result;
		}

		static bool IsDigit(char ch, size_t system = Constant::Number::DEFAULT_SYSTEM)
		{
			if (system == Constant::Number::DEFAULT_SYSTEM)
			{
				return _DIGITS.find(ch) != _DIGITS.end();
			}

			std::set<char> availableSymbols;
			size_t i = 0;
			for (char digit : _DIGITS)
			{
				if (i == system)
				{
					break;
				}
				availableSymbols.emplace(digit);
				++i;
			}
			for (char uppercaseLetter : _UPPERCASE_LETTERS)
			{
				if (i == system)
				{
					break;
				}
				availableSymbols.emplace(uppercaseLetter);
				++i;
			}
			return availableSymbols.find(ch) != availableSymbols.end();
		}

		static bool IsInteger(
				const std::string & str,
				size_t fromIndex,
				size_t & failIndex,
				std::string & goodString,
				size_t system = Constant::Number::DEFAULT_SYSTEM
		)
		{
			if (str.empty())
			{
				return true;
			}
			bool result = true;
			size_t i = fromIndex;
			for (i; i < str.length(); ++i)
			{
				if (!Rule::IsDigit(str.at(i), system))
				{
					result = false;
					failIndex = i;
					goodString = str.substr(fromIndex, i - fromIndex);
					break;
				}
			}
			return result;
		}

	private:
		static bool IsIdentifierSpecialCharacter(char ch)
		{
			return _IDENTIFIER_SPECIAL_CHARACTERS.find(ch) != _IDENTIFIER_SPECIAL_CHARACTERS.end();
		}

		static const std::set<char> _UPPERCASE_LETTERS;

		static const std::set<char> _LOWERCASE_LETTERS;

		static const std::set<char> _DIGITS;

		static const std::set<char> _IDENTIFIER_SPECIAL_CHARACTERS;
	};
}

const std::set<char> Rule::_UPPERCASE_LETTERS = {
		'A',
		'B',
		'C',
		'D',
		'E',
		'F',
		'G',
		'H',
		'I',
		'J',
		'K',
		'L',
		'M',
		'N',
		'O',
		'P',
		'Q',
		'R',
		'S',
		'T',
		'U',
		'V',
		'W',
		'X',
		'Y',
		'Z'
};

const std::set<char> Rule::_LOWERCASE_LETTERS = {
		'a',
		'b',
		'c',
		'd',
		'e',
		'f',
		'g',
		'h',
		'i',
		'j',
		'k',
		'l',
		'm',
		'n',
		'o',
		'p',
		'q',
		'r',
		's',
		't',
		'u',
		'v',
		'w',
		'x',
		'y',
		'z'
};

const std::set<char> Rule::_DIGITS = {
		'0',
		'1',
		'2',
		'3',
		'4',
		'5',
		'6',
		'7',
		'8',
		'9'
};

const std::set<char> Rule::_IDENTIFIER_SPECIAL_CHARACTERS = {
		Constant::Separator::UNDERSCORE_CHARACTER,
		'-'
};

#endif //TOKEN_RULE_H
