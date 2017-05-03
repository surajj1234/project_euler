#ifndef BIGNUM_H
#define BIGNUM_H

#include <string>
#include <iostream>

// Can only handle positive integers
// Supports addition, multiplication only

class BigNum
{
    private:
        std::string number;
        static std::string addStrings(std::string s1, std::string s2);
        static std::string multiplyStrings(std::string s1, std::string s2);
        static std::string eraseLeadingZeros(std::string s);
    public:
        BigNum(void);
        BigNum(std::string num);
        ~BigNum(void);
        BigNum & operator = (const BigNum & val);
        BigNum & operator += (const BigNum & val);
        BigNum & operator *= (const BigNum & val);
        friend std::ostream & operator << (std::ostream & out,
                const BigNum & val);
        friend BigNum operator + (const BigNum & a, const BigNum & b);
        friend BigNum operator * (const BigNum & a, const BigNum & b);
        std::string getString(void);
};

#endif
