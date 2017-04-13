#include <iostream>
#include <vector>
#include <SieveErastothenes.h>
using namespace std;

// What is the value of the first triangle number to have over five hundred
// divisors
long getNumDivisors(long number, SieveErastothenes & sv);

int main(void)
{
    long max = 10000000;
    SieveErastothenes sieve = SieveErastothenes(max);

    int num_divisors = 0;
    for (int n = 2; num_divisors <= 500; n++)
    {
        long triangular_number = n * (n+1) / 2;
        num_divisors = getNumDivisors(triangular_number, sieve);
        cout << n << ":" << triangular_number << ":" << num_divisors << endl;
    }

    return 0;
}


long getNumDivisors(long number, SieveErastothenes & sv)
{
    std::vector<long> factors = sv.getFactors(number);
    long divisors = 1;

    int current_exponent = 0;
    for (int i = 0; i < factors.size(); i += current_exponent)
    {
        current_exponent = 0;
        for (int j = i; j < factors.size(); j++)
        {
            if (factors[j] != factors[i])
                break;
            current_exponent++;
        }
        divisors *= (current_exponent + 1);
    }
    return divisors;
}
