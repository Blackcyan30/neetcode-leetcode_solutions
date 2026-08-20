class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size{(int)heights.size()};
        int l{0}, r{size - 1};
        int max_vol{-1};

        while (l <= r) {
            int curr_max_vol{min(heights[l], heights[r]) * (r - l)};
            max_vol = max(curr_max_vol, max_vol);
            heights[l] < heights[r] ? ++l : --r;
        }
        return max_vol;
        
    }
};
