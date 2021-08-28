class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        string res;
        string seg;
        int idx = s.find(' ');
        while(idx != -1)
        {
            res += s.substr(0, idx);
            res += "%20";
            s = s.substr(idx + 1);
            idx = s.find(' ');
        }
        res += s;
        return res;
    }
};