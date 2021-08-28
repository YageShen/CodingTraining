class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> m;
        if(numbers.size() == 1)
            return numbers[0];
        for(int i = 0; i < numbers.size(); ++i) {
            if(m.count(numbers[i]) == 0)
                m.insert(pair<int, int>(numbers[i], 1));
            else {
                if(++m[numbers[i]] > (numbers.size() / 2)) {
                    return numbers[i];
                }
            }
        }
        unordered_map<int, int>::iterator most_iter;
        int max_num = 0;
        for(unordered_map<int, int>::iterator iter=m.begin(); iter!=m.end(); ++iter) {
            if(iter->second > max_num) {
                most_iter = iter;
                max_num = iter->second;
            }
        }
        return most_iter->first;
    }
};