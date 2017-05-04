#include "BigNum.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

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
    num = eraseLeadingZeros(num);
    number = num;
}

BigNum BigNum::exp(unsigned long exp)
{
    BigNum base = BigNum(number);
    BigNum prod = BigNum("1");

    while (exp)
    {
        if (exp & 0x01)
        {
            prod *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return prod;
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

BigNum operator + (const BigNum & a, const BigNum & b)
{
    BigNum sum;
    sum.number = BigNum::addStrings(a.number, b.number);
    return sum;
}

BigNum operator * (const BigNum & a, const BigNum & b)
{
    BigNum product;
    product.number = BigNum::multiplyStrings(a.number, b.number);
    return product;
}

BigNum & BigNum::operator += (const BigNum & val)
{
    number = addStrings(number, val.number);
    return *this;
}

BigNum & BigNum::operator *= (const BigNum & val)
{
    number = multiplyStrings(number, val.number);
    return *this;
}

std::string BigNum::multiplyStrings(std::string s1, std::string s2)
{
    std::string product = std::string(s1.size() + s2.size(), '0');

    for (int i = s1.size() - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = s2.size() - 1; j >= 0; j--)
        {
            int digit1 = s1[i] - '0';
            int digit2 = s2[j] - '0';
            int prev = product[i + j + 1] - '0';

            int prod = prev + (digit1 * digit2) + carry;
            carry = prod / 10;
            prod = prod % 10;
            product[i + j + 1] = '0' + prod;
        }
        int k = i;
        while(carry)
        {
            int prev = product[k] - '0';
            int sum = prev + carry;
            carry = sum / 10;
            sum = sum % 10;
            product[k] = '0' + sum;
            k--;
        }
    }
    product = eraseLeadingZeros(product);
    return product;
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

std::string BigNum::eraseLeadingZeros(std::string s)
{
    return s.erase(0, std::min(s.find_first_not_of('0'), s.size() - 1));
}

std::string BigNum::getString(void)
{
    return number;
}

BigNum::~BigNum(void)
{
}

