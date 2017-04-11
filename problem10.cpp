#include <iostream>
#include <cmath>
using namespace std;

// Find the sum of all prime numbers below 2 million

bool isPrime(long number);

int main(void)
{
    long max_number = 2000000;
    long sum = 0;

    for (long i = 2; i <= max_number; i++)
    {
        if (isPrime(i))
        {
            sum += i;
        }
    }
    cout << sum << endl;

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
