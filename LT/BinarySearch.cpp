class BinarySearch {
public:
    int binarySearch(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }

    int leftBoundSearch(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                rigth = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                rigth = mid - 1;
            }
        }
        if(left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }

    int rightBoundSearch(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                rigth = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                left = mid + 1;
            }
        }
        if(right < 0 || nums[right] != target)
            return -1;
        return right;
    }
};