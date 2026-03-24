#include <iostream>
using namespace std;

int main()
{
    
    //!  basic loop example
    
    // for (int i = 0; i <= 5; i++) // loop 5 times
    // {
    //     cout << i << "  ";
    // }
    // return 0;

    //! uper wala basuc code tha , usme i loop ke andar hi valid hai agar hame is numbers ko loop ke bahar use krna hai to loop ke bahar hi declare krna hoga
    int num = 0;
    for (num = 0; num <= 100; num++)
    {
        cout << num << "  ";
    }

    cout << endl;
    cout << "latest value after updation is : " << num << endl;

    return 0;
}