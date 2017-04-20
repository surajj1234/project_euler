#include "BigNum.h"
#include <iostream>
#include <stdexcept>

BigNum::BigNum(void)
{
    number = "";
}

BigNum::BigNum(std::string num)
{
    for (unsigned int i = 0; i < num.size(); i++)
    {
        if (num[i] < '0' || num[i] > '9')
            throw std::invalid_argument("received non-numeric digit");
    }
    number = num;
}

BigNum & BigNum::operator=(const BigNum & val)
{
    number = val.number;
    return *this;
}

std::ostream & operator << (std::ostream & out, const BigNum & val)
{
    out << val.number;
    return out;
}

BigNum & BigNum::operator + (const BigNum & val)
{
    number = addStrings(number, val.number);
    return *this;
}

BigNum & BigNum::operator += (const BigNum & val)
{
    number = addStrings(number, val.number);
    return *this;
}

std::string BigNum::addStrings(std::string s1, std::string s2)
{
    std::string result = "";
    int carry = 0;

    if (s1.size() < s2.size())
    {
        s1.insert(0, s2.size() - s1.size(), '0');
    }
    else if (s2.size() < s1.size())
    {
        s2.insert(0, s1.size() - s2.size(), '0');
    }

    int index = s1.size() - 1;

    for (int i = 0; index >= 0; i++, index--)
    {
        int digit1 = s1[index] - '0';
        int digit2 = s2[index] - '0';
        char sum = '0' + digit1 + digit2 + carry;

        sum -= '0';
        if (sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;
        }
        sum += '0';
        result.insert(0, 1, sum);
    }
    if (carry)
        result.insert(0, 1, '0' + carry);
    return result;
}

std::string BigNum::getString(void)
{
    return number;
}

BigNum::~BigNum(void)
{
}

