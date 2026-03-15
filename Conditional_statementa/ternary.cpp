#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    bool isAdult = (age >= 18) ? true : false;
    cout << (char)isAdult << endl;
    return 0;
}