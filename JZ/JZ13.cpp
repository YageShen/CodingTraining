class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        vector<int> odd, even;
        for(int i(0); i < array.size(); ++i) {
            if(array[i] % 2 == 0)
                even.push_back(array[i]);
            else
                odd.push_back(array[i]);
        }
        for(int i(0); i < even.size(); ++i) {
            odd.push_back(even[i]);
        }
        return odd;
    }
};