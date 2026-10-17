class Solution {
public:
    int findMin(vector<int> &nums) {
        size_t N = nums.size();

        int res = nums[0];
        int l{0}, r = N - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = std::min(res, nums[l]);
                break;
            }

            int m = std::floor((l + r)/2);
            res = std::min(res, nums[m]);
            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};
