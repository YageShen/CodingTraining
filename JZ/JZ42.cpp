class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        unordered_set<int> ss;
        vector<int> ret;
        for(int i(0); i < array.size(); ++i) {
            ss.insert(array[i]);
        }
        for(int i(0); i < array.size(); ++i) {
            if(array[i] <= sum / 2) {
                if(array[i] == sum - array[i]) {
                    if(i < array.size() - 1 && array[i+1] == array[i]) {
                        ret.push_back(array[i]);
                        ret.push_back(array[i]);
                        break;
                    }
                }
                else if(ss.count(sum-array[i]) != 0) {
                    ret.push_back(array[i]);
                    ret.push_back(sum-array[i]);
                    break;
                }
            } else {
                break;
            }
        }
        return ret;
    }
};