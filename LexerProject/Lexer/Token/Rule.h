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
			return _letters.find(ch) != _letters.end();
		}

		static bool IsIdentifier(const std::string & str)
		{
			if (str.empty() || !IsLetter(str.front()))
			{
				return false;
			}
			bool result = true;
			for (size_t i = 1; i < str.length(); ++i)
			{
				if (!Rule::IsLetter(str.at(i)) && !Rule::IsDigit(str.at(i)))
				{
					result = false;
					break;
				}
			}

			return result;
		}

		static bool IsDigit(char ch)
		{
			return _digits.find(ch) != _digits.end();
		}

		static bool IsInteger(const std::string & str, size_t fromIndex, size_t & failIndex)
		{
			if (str.empty())
			{
				return true;
			}
			bool result = true;
			size_t i = fromIndex;
			for (i; i < str.length(); ++i)
			{
				if (!Rule::IsDigit(str.at(i)))
				{
					result = false;
					failIndex = i;
					break;
				}
			}
			return result;
		}

	private:
		static const std::set<char> _letters;

		static const std::set<char> _digits;
	};
}

const std::set<char> Rule::_letters = {
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
		'Z',
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
		'z',
		'_'
};

const std::set<char> Rule::_digits = {
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

#endif //TOKEN_RULE_H
