// 1st Task => enter number by user and print their sum
#include <iostream>
using namespace std;

int main()
{
    float a, b;

    cout << "Enter 1st number : ";
    cin >> a;
    cout << "Enter 2nd number : ";
    cin >> b;

    float sum = a + b;
    cout << "Sum is : " << sum << endl;
    return 0;
}