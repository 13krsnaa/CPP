#include <iostream>
using namespace std;

// function for product of two numbers

void product(int a, int b)
{
    int product = a * b;
    cout << "The Product is :" << product << endl;
    ;
}
// int evenOrOdd(product)
// {
//     if(a % 2 == 0)
//     {
//         cout << "The number is even";
//     }
//     else
//     {
//         cout << "The number is odd";
//     }
// }
int main()
{
    product(5, 6);
    // evenOrOdd();
    return 0;
}
