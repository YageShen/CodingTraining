class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        vector<int> stk;
        char op = '+';
        int num = 0;
        for(int i = 0; i < len; ++i) {
            if(isdigit(s[i])) {
                num = num * 10 + (int)(s[i] - '0');
            }
            if(i == len - 1 || (!isdigit(s[i]) && s[i] != ' ')) {
                switch(op) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    case '/':
                        stk.back() /= num;
                        break;
                    default:
                        break;
                }
                op = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};