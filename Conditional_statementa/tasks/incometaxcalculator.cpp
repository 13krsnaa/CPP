#include <iostream>
using namespace std;

int main()
{

    double a;
    double tax = 0;
    cout << "Enter your income : ";
    cin >> a;
    if (a >= 1000000)
    {
        tax = a * 0.30;
        cout << "Your tax slab is : 30% " << endl;
        cout << "your tax value is : " << tax << endl;
    }
    else if (a > 500000 && a < 1000000)
    {
        tax = a * 0.20;
        cout << "Your tax slab is : 20% " << endl;
        cout << "your tax value is : " << tax << endl;
    }
    else if (a > 0 && a <= 500000)
    {
        tax = 0;
        cout << "Your tax slab is : 0% " << endl;
        cout << "your tax value is : " << tax << endl;
    }
    else
    {
        cout << "Enter a valid income " << endl;
        return 0;
    }

    cout << "Tax amount : " << tax << endl;
    cout << "Income after tax : " << (a - tax) << endl;
    return 0;
}
