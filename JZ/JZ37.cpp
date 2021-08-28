class Solution {
public:
    int findNum(vector<int>& data, int k, int left, int right) {
        if(left > right)
            return -1;
        int mid = left + ((right - left) >> 1);
        if(data[mid] == k)
            return mid;
        else if(data[mid] > k)
            return findNum(data, k, left, mid - 1);
        else
            return findNum(data, k, mid + 1, right);
    }
    int GetNumberOfK(vector<int> data ,int k) {
        int idx = findNum(data, k, 0, data.size() - 1);
        if(idx == -1)
            return 0;
        int p1 = idx, p2 = idx;
        if(data[0] == k)
            p1 = -1;
        else {
            while(data[--p1] == k);
        }
        if(data[data.size() - 1] == k)
            p2 = data.size();
        else {
            while(data[++p2] == k);
        }
        return p2 - p1 - 1;
    }
};