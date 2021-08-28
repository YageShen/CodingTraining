#include <iostream>

using namespace std;

int main()
{
    double num;
    while(cin >> num)
    {
        float low, up, mid;
        if(num < 0)
        {
            up = 0;
            low = num > -1 ? -1 : num;
        }
        else
        {
            low = 0;
            up = num < 1 ? 1 : num;
        }
        mid = (low + up) / 2;
        while(up - low > 0.1)
        {
            if(mid * mid * mid > num)
            {
                up = mid;
            }
            else
            {
                low = mid;
            }
            mid = (low + up) / 2;
        }
        printf("%.1f", mid + 0.005);
    }
    return 0;
}