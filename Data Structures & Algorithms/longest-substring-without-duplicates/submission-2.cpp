class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l{0};
        size_t n = s.size();
        unordered_set<char> seen{};
        int longest_sub_str_len{0};
        for (int r{0}; r < n; ++r) {
            while (seen.contains(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            longest_sub_str_len = std::max(longest_sub_str_len, r - l + 1);
            seen.insert(s[r]);
        }
        return longest_sub_str_len;
        
    }
};
