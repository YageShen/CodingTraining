#include <iostream>

using namespace std;

int main()
{
    int oneMonthNum = 1, twoMonthNum = 0, adultNum = 0;
    int month, max_month = 1;
    int total[100][3] = {0};
    total[0][0] = 1;
    while(cin >> month)
    {
        if(month > max_month)
        {
            for(int i(max_month); i < month; i++)
            {
                adultNum += twoMonthNum;
                twoMonthNum = oneMonthNum;
                oneMonthNum = adultNum;
                
                total[i][0] = oneMonthNum;
                total[i][1] = twoMonthNum;
                total[i][2] = adultNum;
            }
            max_month = month;
            cout << oneMonthNum + twoMonthNum + adultNum << endl;            
        }
        else
        {
            cout << total[month-1][0] + total[month-1][1] + total[month-1][2] << endl; 
        }

    }
    return 0;
}