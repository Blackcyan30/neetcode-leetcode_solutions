class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> my_set{nums.begin(), nums.end()};
        int longest{0};

        for(const auto& n : nums) {
           if (!my_set.contains(n-1)) {
                int curr_seq_len{0};
                while (my_set.contains(n + curr_seq_len)) {
                    ++curr_seq_len;
                    longest = std::max(longest, curr_seq_len);
                }
           } 
        }
        return longest;
    }
};
