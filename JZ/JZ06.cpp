class Solution {
public:
    int minNumberInRotateArray(vector<int>& rotateArray) {
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = (left + right) / 2;
        while(right - left > 1) {
            if(rotateArray[mid] > rotateArray[right]) {
                left = mid;
            }
            else if(rotateArray[mid] < rotateArray[right]) {
                right = mid;
            }
            else {
                --right;
            }
            mid = (left + right) / 2;
        }
        return min(rotateArray[left], rotateArray[right]);
    }
};