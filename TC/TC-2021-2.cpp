#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string input;
    int k;
    cin >> input;
    cin >> k;
    int len = input.size();
    set<string> ss;
    for(int i = 0; i < len; ++i) {
		ss.insert(input.substr(i, len - i));
    }
    set<string>::iterator iter;
    set<string> outSet;
    while(k > 0) {
        iter = ss.begin();
        string str = *iter;
        int subLen = str.size();
        for(int i = 1; i <= subLen; ++i) {
            string temp = str.substr(0, i);
            if(outSet.count(temp) == 0) {
                outSet.insert(temp);
                --k;
                if(k ==0) {
                    cout << temp << endl;
                    return 0;
                }
            }
        }
        ss.erase(*iter);
    }
    
    return 0;
}
