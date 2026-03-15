#include <iostream>
using namespace std;

int main()
{
    float PI = 3.1414;

    cout  << (int)(PI) << endl;       // 3 aaya kyuki float ko int me convert kia explicit convesion se
    cout << ((float)10 / 3) << endl; // int aata par float aaya kyuki float lgaya tha
    cout << (char)('A' + 1) << endl; // int 66 aani this par char ayu kyuki a ki value me 1 add kra to b value milli
    cout << (char)('a' + 1) << endl;
    cout << (bool)3 + 2 << endl;
    
    


    //ye implicit conversion hai to isme sabse badi value double hai to (23.344 + 32 + 'B') ye se sab double me convert ho jayenge jis se output dpouble me aayega 
       
    cout  << (23.344 + 32 + 'B') << endl;

    return 0;
}

