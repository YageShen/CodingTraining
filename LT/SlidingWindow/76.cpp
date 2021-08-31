class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, need;
        int left = 0, right = 0;
        for (auto c : t) {
            ++need[c];
        }
        int valid = 0;
        int len = INT_MAX, start = 0;
        while (right < s.size()) {
            char c = s[right];
            ++right;
            if (need.count(c) > 0) {
                ++window[c];
                if (window[c] == need[c]) {
                    ++valid;
                }
            }
            while (valid == need.size()) {
                if ((right - left) < len) {
                    len = right - left;
                    start = left;
                }
                char c = s[left];
                ++left;
                if(need.count(c) > 0) {
                    if(window[c] == need[c]) {
                        --valid;
                    }
                    --window[c];
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};