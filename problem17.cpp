#include <iostream>
#include <string>

std::string numToText(int num)
{
    std::string result;

    std::string hundreds[10] = {"", "one hundred", "two hundred",
    "three hundred", "four hundred", "five hundred",
    "six hundred", "seven hundred", "eight hundred",
    "nine hundred"};

    std::string tens[10] = {"", "ten ", "twenty ", "thirty ", "forty ",
        "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};

    std::string ones[10] = {"", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine"};

    std::string teens[10] = {"", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    int hundred = num / 100;
    int ten = (num / 10) % 10;
    int one = num % 10;

    if (hundred)
    {
        result += hundreds[hundred];
        if (ten || one)
        {
            result += " and ";
        }
    }

    if (ten)
    {
        if (ten == 1 && one)
        {
            result += teens[one];
        }
        else
        {
            result += tens[ten];
        }
    }

    if (one)
    {
        if (ten != 1)
        {
            result += ones[one];
        }
    }

    return result;
}

int countNoSpaces(std::string s)
{
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
            result++;
    }
    return result;
}

int main()
{
    int count = 0;
    for (int i = 1; i < 1000; i++)
    {
        count += countNoSpaces(numToText(i));
        std::cout << i << " : " << numToText(i)  << " " << count << std::endl;
    }
    return 0;
}
