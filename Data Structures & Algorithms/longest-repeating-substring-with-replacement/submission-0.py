from collections import defaultdict

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq_map = defaultdict(int)
        l = 0
        max_len = 0 # Length of longest valid window found soo far.

        for right, char in enumerate(s):    
            # Algo to follow
            # 1. Add the new character to our frequency dictionary
            # 2. Check if the window requires more than k replacements
            # 3. If invalid, shrink the window from the left
            # 4. Update our longest window
 
            # Add new char to freq map
            freq_map[char] += 1

            # check if window is valid.
            # validity check would be: replacementes needed = window len - max freq from map
            replacements_needed = ((right - l) + 1) - max(freq_map.values())
            # If invalid shrink window until valid
            while (replacements_needed > k):
                freq_map[s[l]] -= 1
                l += 1
                replacements_needed = ((right - l) + 1) - max(freq_map.values())
            max_len = max(max_len, (right - l) + 1)

        return max_len
            

        
