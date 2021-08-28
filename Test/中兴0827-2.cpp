class Solution {
public:
    int diskRead(vector<int>& a, int pos) {
            sort(a.begin(), a.end());
            int len = a.size();
            int firstMove = min(abs(pos - a[0]), abs(a[len-1] - pos));
            return firstMove + (a[len - 1] - a[0]);
    }
}；