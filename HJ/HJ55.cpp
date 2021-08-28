#include <iostream>

using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        int cnt = 0;
        for(int i(1); i <= N; ++i)
        {
            int temp = i;
            if(temp % 7 ==0)
                cnt ++;
            else
            {
                while(temp > 0)
                {
                    if(temp % 10 == 7)
                    {
                        cnt ++; 
                        break;
                    }
                    temp /= 10;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}