#include <iostream>
#include <cmath>
using namespace std;

// Find the 10001st prime number

bool isPrime(long number);

int main(void)
{
    long max_number = 1000000;
    long prime_ctr = 0;
    const long target_prime = 10001;

    for (long i = 2; i < max_number; i++)
    {
        if (isPrime(i))
        {
            prime_ctr++;
            cout << prime_ctr << " " << i << "\n";
        }
        if (prime_ctr == target_prime)
            break;
    }

    return 0;
}

bool isPrime(long number)
{
    bool result = true;
    long max = sqrt(number);
    for (long i = 2; i <= max; i++)
    {
        if (number % i == 0)
        {
            result = false;
            break;
        }
    }
    return result;
}
