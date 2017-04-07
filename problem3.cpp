#include <iostream>
#include <cmath>
using namespace std;

// Find largest prime factor of 600851475143

bool isPrime(long number);

int main(void)
{
    long number = 600851475143;
    long largest_prime_factor = 1;
    long n = number;

    // Using a modified trial division algorithm to determine prime factors
    for (long i = 2; i <= sqrt(number); i++)
    {
        if (n % i != 0)
            continue;

        if (isPrime(i))
        {
            while (n % i == 0)
            {
                n /= i;
                cout << i << "\n";
                largest_prime_factor = i;
            }
        }
    }
    if (n > 1)
    {
        cout << n << "\n";
        largest_prime_factor = n;
    }
    cout << "Largest prime factor of " << number << " is "
         << largest_prime_factor << "\n";
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
