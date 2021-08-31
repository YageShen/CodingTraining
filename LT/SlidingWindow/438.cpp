class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if (p.size() > s.size()) {
            return ret;
        }
        unordered_map<char, int> window, need;
        for(auto c : p)
            ++need[c];
        int left = 0, right = 0;
        int valid = 0;
        while (right < p.size()) {
            char c = s[right];
            ++right;
            if(need.count(c) > 0) {
                ++window[c];
                if(window[c] == need[c])
                    ++valid;
            }
        }
        if(valid == need.size())
            ret.push_back(left);
            
        while(right < s.size()) {
            char cr = s[right];
            ++right;
            if(need.count(cr) > 0) {
                ++window[cr];
                if(window[cr] == need[cr])
                    ++valid;
            }

            char cl = s[left];
            ++left;
            if(need.count(cl) > 0) {
                if(window[cl] == need[cl])
                    --valid;
                --window[cl];
            }

            if(valid == need.size())
                ret.push_back(left);
        }
        return ret;
    }
};