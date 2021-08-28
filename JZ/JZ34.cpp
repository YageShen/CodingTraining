class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> m;
        if(str.empty())
            return -1;
        for(int i(0); i < str.size(); ++i) {
            if(m.count(str[i]) == 0) {
                m.insert(pair<char, int>(str[i], i));
            }
            else {
                m[str[i]] = 10001;
            }
        }
        int min_idx = 10001;
        for(unordered_map<char, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
            if(iter->second < min_idx)
                min_idx = iter->second;
        }
        return min_idx == 10001 ? -1 : min_idx;
    }
};