class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0 
        n = len(s)
        hash_set = set()
        longest_sub_str = 0
        for r in range(n):
            while (s[r] in hash_set):
                hash_set.remove(s[l])
                l+=1
            hash_set.add(s[r])
            longest_sub_str = max(longest_sub_str, r - l + 1)
        return longest_sub_str



        