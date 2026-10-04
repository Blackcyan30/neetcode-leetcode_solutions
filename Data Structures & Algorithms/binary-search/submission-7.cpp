class Solution {
public:
    int search(vector<int>& nums, int target) {
        int64_t n{static_cast<int64_t>(nums.size())};
        int64_t l{0}, r{n-1};

        while (l <= r) {
            int64_t mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1; 
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

};
