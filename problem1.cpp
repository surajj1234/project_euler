#include <iostream>
using namespace std;

// Find the sum of all the multiples of 3 or 5 below 1000
int main(void)
{
    int max = 1000, sum = 0;
    for (int i = 1; i < max; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }
    cout << sum << "\n";
    return 0;
}
