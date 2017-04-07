#include <iostream>
#include <string.h>
using namespace std;

// Find the largest palindrome made from the product of two 3-digit numbers

bool isPalindrome(int number);

int main(void)
{
    int largest = 0;
    for (int i  = 999; i > 900; i--)
    {
        for (int j = 999; j > 900; j--)
        {
            int product = i*j;
            if (isPalindrome(product))
            {
                cout << i << " * " << j << " = " << product << "\n";
                if (product > largest)
                    largest = product;
            }
        }
    }
    cout << "largest palindrome is " << largest << "\n";
    return 0;
}

bool isPalindrome(int number)
{
    char buffer[10] = {0};
    char reverse[10] = {0};

    sprintf(buffer, "%d", number);
    int len = strlen(buffer);
    for (int i = 0; i < len; i++)
    {
        reverse[i] = buffer[len - i - 1];
    }

    if (strcmp(buffer, reverse) == 0)
        return true;
    else
        return false;
}
