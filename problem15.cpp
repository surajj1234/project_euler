#include <iostream>

long combinations(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    double c = 1;
    for (int i = 0; i < k; i++)
    {
        c = c * (n - i) / (i + 1);
    }
    return (long)c;
}

int main()
{
    std::cout << combinations(40, 20) << std::endl;
    return 0;
}
