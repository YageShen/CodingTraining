class Solution {
public:
    string ReverseSentence(string str) {
        stack<string> s;
        string ret;
        if(str.empty())
            return ret;
        while(!str.empty()) {
            int p = str.find(' ');
            if(p != -1) {
                s.emplace(str.substr(0, p));
                str = str.substr(p + 1);
            }
            else {
                s.emplace(str);
                break;
            }
        }
        while(!s.empty()) {
            ret.append(s.top());
            ret.append(" ");
            s.pop();
        }
        return ret.substr(0, ret.size() - 1);
    }
};