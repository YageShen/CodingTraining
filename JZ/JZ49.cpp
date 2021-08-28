class Solution {
public:
    int StrToInt(string str) {
        int ret = 0;
        int idx = 0;
        bool neg = false;
        if(str[idx] == '-') {
            ++idx;
            neg = true;
        } 
        else if(str[idx] == '+') ++idx;
        for(int i = idx; i < str.size(); ++i) {
            int temp = str[i] - '0';
            if(temp >= 0 && temp <= 9) {
                ret = ret * 10 + temp;
            }
            else
                return 0;
        }
        return neg ? -ret : ret;
    }
};