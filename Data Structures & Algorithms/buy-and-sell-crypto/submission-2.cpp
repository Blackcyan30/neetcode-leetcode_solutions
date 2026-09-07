static const auto fast_io = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
        
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price{prices[0]};
        int max_price{0};
        for (const auto& curr_price : prices) {
            if (min_price < curr_price) {
                max_price = std::max(max_price, curr_price - min_price);
            } else {
                min_price = curr_price;
            }
        }
        return max_price;
    }
};
