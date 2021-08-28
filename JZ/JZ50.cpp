class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        // write code here
        int len = numbers.size();
        unordered_set<int> ss;
        for(int i = 0; i < len; ++i) {
            int temp = numbers[i];
            if(temp >= len) return -1;
            if(ss.count(temp) == 0)
                ss.insert(temp);
            else
                return temp;
        }
        return -1;
    }
};