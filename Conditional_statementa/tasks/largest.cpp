//! print largest of 3 numbers

#include <iostream>
using namespace std;

int main()
{

    int a, b, c;

    cout << "Enter 1st number : " << endl;
    cin >> a;
    cout << "Enter 2nd number : " << endl;
    cin >> b;
    cout << "Enter 3d number : " << endl;
    cin >> c;

    if (a > b && a > c)
    {
        cout << "Largest number is : " << a << endl;
    }
    else if (b > a && b > c)
    {
        cout << "Largest number is : " << b << endl;
    }
    else if (c > a && c > b)
    {
        cout << "Largest number is : " << c << endl;
    }
    else
    {
        cout << " Enter a valid number " << endl;
    }
    return 0;
}