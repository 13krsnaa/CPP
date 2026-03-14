#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a = 10;
    float PI = 3.14;
    char name = 'Kri';
    bool isTrue = true;
    double PI2 = 3.142343343;

    cout << setprecision(5) << "float value is : " << PI << endl;
    cout << setprecision(14) << "Double value is : " << PI2 << endl;
    cout << "Interger value is :" << a << endl;
    cout << " is hea student : " << isTrue << endl;
    cout << "My name is : " << name << endl;
    return 0;
}