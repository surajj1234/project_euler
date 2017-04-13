#include "SieveErastothenes.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

SieveErastothenes::SieveErastothenes(unsigned long max_number)
{
    if (max_number < 2)
        throw std::invalid_argument("Sieve size must be greater than 1");

    sieve_size = max_number;
    numbers = new bool[sieve_size];
    std::fill_n(numbers, sieve_size, true);
    numbers[0] = false;
    numbers[1] = false;
    for (unsigned long i = 2; i*i <= sieve_size; i++)
    {
        if (numbers[i])
        {
            for (unsigned long j = i*i; j <= sieve_size; j += i)
            {
                numbers[j] = false;
            }
        }
    }
    for (unsigned long i = 2; i < sieve_size; i++)
    {
        if (numbers[i])
            primes.push_back(i);
    }
}

bool SieveErastothenes::isPrime(unsigned long number)
{
    if (number >= sieve_size)
        throw std::invalid_argument("Sieve bounds exceeded");
    return numbers[number];
}

long SieveErastothenes::getNextPrime(unsigned long number)
{
    if (number > sieve_size - 1)
        throw std::invalid_argument("Sieve bounds exceeded");

    unsigned long index = number + 1;
    while(index < sieve_size)
    {
        if (numbers[index] == true)
            return index;
        index++;
    }
    throw std::invalid_argument("Sieve bounds exceeded");
}

long SieveErastothenes::getNthPrime(unsigned long n)
{
    if (n > primes.size())
        throw std::invalid_argument("Sieve does not contain these many primes");

    return primes[n-1];
}

long SieveErastothenes::getNumberOfPrimes(void)
{
    return primes.size();
}

long SieveErastothenes::getNumberOfPrimesUpTo(unsigned long number)
{
    long next_prime = getNextPrime(number);
    long num = 0;
    for (auto p : primes)
    {
        num++;
        if (p == next_prime)
            break;
    }
    return num;
}

std::vector<long> SieveErastothenes::getFactors(long number)
{
    // Using trial division
    std::vector<long> factors;
    for (long i = 2; i*i <= number; i = getNextPrime(i))
    {
        while (number % i == 0)
        {
            factors.push_back(i);
            number /= i;
        }
    }
    if (number > 1)
        factors.push_back(number);
    return factors;
}

SieveErastothenes::~SieveErastothenes()
{
    primes.clear();
    delete[] numbers;
}
