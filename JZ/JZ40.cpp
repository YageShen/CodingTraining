class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        unordered_set<int> ss;
        for(int i = 0; i < array.size(); ++i) {
            if(ss.count(array[i]) != 0) {
                ss.erase(array[i]);
            }
            else
                ss.insert(array[i]);
        }
        int val1 = *ss.begin(), val2 = *(++ss.begin());
        vector<int> ret;
        ret.push_back(min(val1, val2));
        ret.push_back(max(val1, val2));
        return ret;
    }
};