#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    unordered_map<string, vector<string>> subClass;
    unordered_map<string, vector<string>> instance;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string str1, str2, str3;
        cin >> str1 >> str2 >> str3;
        if(str2 == "subClassOf") {
            subClass[str3].push_back(str1);
        }
        else if(str2 == "instanceOf") {
            instance[str3].push_back(str1);
        }
    }
    string needFind;
    vector<string> ret;
    cin >> needFind;
    for(unordered_map<string, vector<string>>::iterator it = instance.begin(); it != instance.end(); ++it) {
        if(it->first == needFind) {
            ret.insert(ret.end(), it->second.begin(), it->second.end());
        }
    }
    for(unordered_map<string, vector<string>>::iterator it = subClass.begin(); it != subClass.end(); ++it) {
        if(it->first == needFind) {
            for(int i = 0; i < (it->second).size(); ++i) {
                if(instance.count(it->second[i]) > 0) {
                    ret.insert(ret.end(), instance[it->second[i]].begin(), instance[it->second[i]].end());
                }
            }
        }
    }
    sort(ret.begin(), ret.end());
    for(int i = 0; i < ret.size() - 1; ++i) {
        cout << ret[i] << ' ';
    }
    cout << ret[ret.size() - 1];        
    //cout << endl;
    return 0;
}
