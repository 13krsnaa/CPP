//! take 2 numbers form user and print the largest number

#include <iostream>
using namespace std;

int main()
{

    int a, b;
    cout << "Enter 1st number : " << endl;
    cin >> a;

    cout << "Enter 2nd number " << endl;
    cin >> b;

    if (a > b)
    {
        cout << "Largest number is : " << a << endl;
    }
    else
    {
        cout << "Largest number is  " << b << endl;
    }
    return 0;
}