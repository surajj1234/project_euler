#include <iostream>
#include "BigNum.h"

int main()
{
    BigNum n = BigNum("2");
    long m = 1000;
    std::string exp = n.exp(m).getString();
    std::cout << n << " exp " << m << " = " << exp << std::endl;

    long sum = 0;
    for (int i = 0; i < exp.size(); i++)
    {
        sum += exp[i] - '0';
    }
    std::cout << "Sum of digits = " << sum << std::endl;
    return 0;
}
