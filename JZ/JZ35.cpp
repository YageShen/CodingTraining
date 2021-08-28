class Solution {
public:
    void merge(vector<int>& array, vector<int>& temp, int left, int mid, int right) {
        int p1 = left, p2 = mid + 1, p = p1;
        while(p1 <= mid && p2 <= right) {
            if(array[p1] <= array[p2]) {
                temp[p++] = array[p1++];
            }
            else {
                pairsOfInverse += (mid - p1 + 1);
                if(pairsOfInverse >= 1000000007) pairsOfInverse -= 1000000007;
                temp[p++] = array[p2++];
            }
        }
        while(p1 <= mid) temp[p++] = array[p1++];
        while(p2 <= right) {
            temp[p++] = array[p2++];
        }
        copy(temp.begin() + left, temp.begin() + right + 1, array.begin() + left);
    }
    void mergeSort(vector<int>& array, vector<int>& temp, int left, int right) {
        if(left >= right)
            return;
        int mid = left + ((right - left) >> 1);
        mergeSort(array, temp, left, mid);
        mergeSort(array, temp, mid + 1, right);
        merge(array, temp, left, mid, right);
    }
    int InversePairs(vector<int> data) {
        vector<int> temp(data.size());
        pairsOfInverse = 0;
        mergeSort(data, temp, 0, data.size() - 1);
        return pairsOfInverse;
    }
private:
    int pairsOfInverse = 0;
};