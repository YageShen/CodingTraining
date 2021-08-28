#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define MIN_NUM 1e-6

int main()
{
    string input;
    vector<string> res;
    while(cin >> input)
    {
        int idx = input.find('/');
        double dst = stod(input.substr(0, idx)) / stod(input.substr(idx+1));
        double sum = 0;
        int i = 2;
        while(true)
        {
            if(sum > (dst - MIN_NUM) && sum < (dst + MIN_NUM))
            {
                break;
            }
            if((sum + 1.0 / (double)i) < dst)
            {
                res.push_back("1/"+to_string(i));
               sum += 1.0 / (double)i;
            }
            i ++;
        }
        for(int i(0); i < (res.size() - 1); ++i)
            cout << res[i] << '+';
        cout << res[res.size()-1] << endl;
        // for(auto s : res)
        //     cout << s << '+'; 
        res.clear();
    }
    return 0;
}