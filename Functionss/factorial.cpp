#include <iostream>
using namespace std;

void factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    cout << "The factorial of " << n << " is " << fact << endl;
}

int main()
{
    factorial(7);
    return 0;
}