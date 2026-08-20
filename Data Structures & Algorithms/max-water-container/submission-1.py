class Solution:
    def maxArea(self, heights: List[int]) -> int:
        n = len(heights) - 1
        l, r = 0, n
        max_area = -1

        while l <= r :
            width = r - l
            height = min(heights[r], heights[l])
            curr_max_area = width * height
            max_area = max(max_area, curr_max_area)
            if heights[l] > heights[r]:
                r -= 1
            else:
                l += 1

        return max_area
               



        