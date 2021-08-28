#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    int max_sub = 1;
    for(int i(2); i <= min(num1, num2); ++i)
    {
        if(num1 % i == 0 && num2 % i == 0)
            max_sub  = i;
    }
    cout << num1 * num2 / max_sub << endl;
//     for(int i = max(num1, num2); i <= num1 * num2; ++i)
//     {
//         if(i % num1 ==0 && i % num2 == 0)
//         {
//             cout << i << endl;
//             break;
//         }
//     }
    return 0;
}