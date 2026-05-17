class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        bucket = defaultdict(list)

        def get_hash_code(s):
            char_count = [0] * 26
            for ch in s:
                char_count[ord(ch) - ord('a')] += 1

            return hash(tuple(char_count))

        for s in strs:
            hash_code = get_hash_code(s)
            bucket[hash_code].append(s)

        return [group for group in bucket.values()]
            
            