#include <iostream>

using namespace std;

int main()
{
    int N;
    int height[3000];
    int dp_up[3000], dp_down[3000];
    while(cin >> N)
    {
        for(int i(0); i < N; ++i)
        {
            cin >> height[i];
            dp_up[i] = 1;
            for(int j(0); j < i; ++j)
            {
                if(height[i] > height[j])
                {
                    dp_up[i] = max(dp_up[i], dp_up[j] + 1);
                }
            }
        }
        for(int i(N-1); i >= 0; --i)
        {
            dp_down[i] = 1;
            for(int j(N-1); j > i; --j)
            {
                if(height[i] > height[j])
                {
                    dp_down[i] = max(dp_down[i], dp_down[j] + 1);
                }
            }
        }
        int max_num = 0;
        for(int i(0); i < N; ++i)
        {
            max_num = max(dp_up[i]+dp_down[i]-1, max_num);
        }
        cout << N - max_num << endl;
        
//         for(int i(0); i < N; ++i)
//             cout << dp_up[i] << ' ';
//         cout << endl;
//         for(int i(0); i < N; ++i)
//             cout << dp_down[i] << ' ';
//         cout << endl;
    }
    
    return 0;
}