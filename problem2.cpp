#include <iostream>
using namespace std;

// Find sum of even-valued Fibonacci numbers below 4 million
int main(void)
{
    long a = 0, b = 1;
    long c = a + b;
    long sum = 0;
    long max = 4000000;
    while(c < max)
    {
        if (c % 2 == 0)
        {
            sum += c;
        }
        a = b;
        b = c;
        c = a + b;
    }
    cout << sum << "\n";
    return 0;
}
