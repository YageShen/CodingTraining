class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> window, need;
        for(auto c : s1)
            ++need[c];
        int left = 0, right = 0;
        int valid = 0;
        while (right < s1.size()) {
            char c = s2[right];
            ++right;
            if(need.count(c) > 0) {
                ++window[c];
                if(window[c] == need[c])
                    ++valid;
            }
        }
        while(right < s2.size() && valid < need.size()) {
            char cr = s2[right];
            ++right;
            if(need.count(cr) > 0) {
                ++window[cr];
                if(window[cr] == need[cr])
                    ++valid;
            }

            char cl = s2[left];
            ++left;
            if(need.count(cl) > 0) {
                if(window[cl] == need[cl])
                    --valid;
                --window[cl];
            }
        }
        return valid == need.size();
    }
};