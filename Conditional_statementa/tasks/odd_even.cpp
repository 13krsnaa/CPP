//! here we will check if the entered number is even or odd

#include <iostream>
using namespace std;

int main()
{

    int a;

    cout << "Please enter the number " << endl;
    cin >> a;

    if (a % 2 == 0)
    {
        cout << "enterd numher is even " << endl;
    }
    else
    {
        cout << "Entered number is odd" << endl;
    }
    return 0;
}