#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int sum_one = 0, sum_two = 0;

bool dfs(int i)
{
    if(i >= vec.size())
    {
        if(sum_one == sum_two)
            return true;
        else
            return false;
    }
    
    sum_one += vec[i];
    if(dfs(i+1))
        return true;
    else
    {
        sum_one -=vec[i];
        sum_two += vec[i];
        if(dfs(i+1))
            return true;
        else
        {
            sum_two -=vec[i];
            return false;
        }  
    }
    return false;
}

int main()
{
    int n;
    while(cin >> n)
    {
        sum_one = 0; sum_two = 0;
        for(int i(0); i < n; ++i)
        {
            int temp;
            cin >> temp;
            if(temp % 5 == 0)
            {
                sum_one += temp;
            }
            else if(temp % 3 == 0)
            {
                sum_two += temp;
            }
            else
                vec.push_back(temp);
        }
        if(dfs(0))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        vec.clear();
    }
    return 0;
}