#include <iostream>

int collatz(long n)
{
    int terms = 0;
    long n_initial = n;
    while (n >= 1)
    {
        terms++;
        //std::cout << n << ",";
        if (n == 1)
            break;

        if (n % 2 == 0)
            n = n / 2;
        else
            n = (3 * n) + 1;
    }
    //std::cout << n_initial << " :" << terms <<std::endl;
    return terms;
}

int main(void)
{
    int max_terms = 0, max_num = 0;
    for (int i = 0; i < 1000000; i++)
    {
        int terms = collatz(i);
        if (terms > max_terms)
        {
            max_terms = terms;
            max_num = i;
            std::cout << i << ":" << max_terms << std::endl;
        }
    }
    return 0;
}
