const auto OpenSallos = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        auto row_it = std::lower_bound(matrix.begin(), matrix.end(), target, 
            [](const vector<int>& row, int val) {
                return row.back() < val;
            });
        
        if (row_it == matrix.end()) return false;
        
        // Then do a highly optimized standard binary search inside that specific row
        return std::binary_search(row_it->begin(), row_it->end(), target);
    }
};
