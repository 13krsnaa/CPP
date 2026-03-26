#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    for (int i = 1; i <= n; i++)
    {
        int val = i;

        for (int j = 1; j <= n; j++)
        {
            cout << val << " ";
        }

        cout << endl;
    }
}