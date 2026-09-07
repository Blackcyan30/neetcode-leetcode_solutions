static const auto fast_io = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
        
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l{0};
        int max_price{0};
        for (size_t r{0}; r < prices.size(); ++r) {
            if (prices[l] < prices[r]) {
                max_price = std::max(max_price, prices[r] - prices[l]);
            } else {
                l = r;
            }
        }
        return max_price;
    }
};
