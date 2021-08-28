#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 class Solution {
 public:
     vector<int> dfs(vector<int>& a, int left, int right) {
         vector<int> ret(2);
         if(right - left == 1) {
             ret[0] = abs(a[left] - a[right]);
             ret[1] = a[left] ^ a[right];
             return ret;
         }
         vector<int> ret1(2), ret2(2);
         ret1 = dfs(a, left+1, right);
         ret2 = dfs(a, left, right-1);
         int cost1 = ret1[0] + abs(ret1[1] - a[left]);
         int cost2 = ret2[0] + abs(ret2[1] - a[right]);
         if(cost1 < cost2) {
             ret[0] = cost1;
             ret[1] = ret1[1] ^ a[left];
         }
         else {
             ret[0] = cost2;
             ret[1] = ret2[1] ^ a[right];
         }
         return ret;
     }

     long long mergeProps(vector<int>& a) {
         return dfs(a, 0, a.size()-1)[0];
     }
 };

int main() {
     Solution sol;
    vector<int> a = {1,4,8};
     cout << sol.mergeProps(a) << endl;
//    cout << endl;
    return 0;
}
