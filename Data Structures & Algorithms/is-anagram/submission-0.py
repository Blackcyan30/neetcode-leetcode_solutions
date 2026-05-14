class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        char_count_s = [0] * 26
        char_count_t = [0] * 26
        s_len, t_len = len(s), len(t)

        if s_len != t_len:
            return False

        for i in range(s_len):
            alphabet_pos = ord(s[i]) - ord('a')
            char_count_s[alphabet_pos] += 1
            alphabet_pos = ord(t[i]) - ord('a')
            char_count_t[alphabet_pos] += 1

        return char_count_t == char_count_s

        
            

