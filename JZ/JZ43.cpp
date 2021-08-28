class Solution {
public:
    string LeftRotateString(string str, int n) {
        string ret;
        int len = str.size();
        while(ret.size() < len) {
            ret += str[(n++)%len];
        }
        return ret;
    }
};