#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<int> nums, int left, int right) {
    if(left > right) return 0;
    if(left == right) return nums[left];
    int min = *min_element(nums.begin()+left,nums.begin()+right+1);
    vector<int> left_vec;
    vector<int> right_vec;
    int lleft = left;
    for(int i = left; i <= right; ++i) {
        nums[i] -= min;
        if(nums[i] == 0) {
            left_vec.push_back(lleft);
            right_vec.push_back(i-1);
            lleft = i+1;
        }
    }
    left_vec.push_back(lleft);
    right_vec.push_back(right);
    int ret = min;
    for(int i = 0;i < left_vec.size(); ++i)
        ret += dfs(nums, left_vec[i], right_vec[i]);
    return ret;
}

int main() {
    vector<int> nums{0,3,2,4};
    //cout << *max_element(nums.begin()+1,nums.begin()+3) << endl;
    int ans = dfs(nums, 0, nums.size()-1);
    cout << ans;
    return 0;
}