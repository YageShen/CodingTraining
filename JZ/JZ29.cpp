class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> &input, int k) {
        for(int i(0); i < k; ++i) {
            for(int j(0); j < input.size()-i-1; ++j) {
                if(input[j] < input[j+1]) {
                    swap(input[j], input[j+1]);
                }
            }
        }
        return vector<int>({input.end()-k, input.end()});
    }
};