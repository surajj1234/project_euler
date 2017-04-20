#ifndef BIGNUM_H
#define BIGNUM_H

#include <string>
#include <iostream>

// Can only handle positive integers
// Supports addition only

class BigNum
{
    private:
        std::string number;
        std::string addStrings(std::string s1, std::string s2);
    public:
        BigNum(void);
        BigNum(std::string num);
        ~BigNum(void);
        BigNum & operator = (const BigNum & val);
        friend std::ostream & operator << (std::ostream & out,
                const BigNum & val);
        BigNum & operator + (const BigNum & val);
        BigNum & operator += (const BigNum & val);
        std::string getString(void);
};

#endif
