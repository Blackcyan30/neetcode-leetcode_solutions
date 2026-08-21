class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = static_cast<int>(numbers.size());
        int l{0}, r{n - 1};

        while (l < r) {
            int current_sum{numbers[l] + numbers[r]};
            if (current_sum == target) return {l+1, r+1};
            if (current_sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return {};
    }
};
