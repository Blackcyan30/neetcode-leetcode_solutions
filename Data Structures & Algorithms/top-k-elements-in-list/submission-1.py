class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_count = {}
        q = []
        res = []

        for n in nums:
            num_count[n] = num_count.get(n, 0) + 1

        for key, v in num_count.items():
            heapq.heappush(q, (-v, key))
        
        for _ in range(0, k):
            res.append(heapq.heappop(q)[1])
            
        return res

        

        
        