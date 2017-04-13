#ifndef SIEVE_ERASTOTHENES_H
#define SIEVE_ERASTOTHENES_H

#include <cstdint>
#include <vector>

class SieveErastothenes
{
    private:
        bool * numbers;
        unsigned long sieve_size;
        std::vector<long> primes;
    public:
        SieveErastothenes(unsigned long max_number);    // Should handle ~100M easily
        bool isPrime(unsigned long number);
        long getNextPrime(unsigned long number);
        long getNthPrime(unsigned long n);
        long getNumberOfPrimes(void);
        long getNumberOfPrimesUpTo(unsigned long number);
        std::vector<long> getFactors(long number);
        ~SieveErastothenes();
};



#endif
