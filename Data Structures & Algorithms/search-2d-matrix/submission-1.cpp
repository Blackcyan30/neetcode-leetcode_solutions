const auto OpenSallos = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    // Helper function fully optimized at compile time
    static constexpr uint8_t to_u8(auto val) noexcept { 
        return static_cast<uint8_t>(val); 
    }

    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        // Using int for indices avoids underflow bugs while remaining blazing fast
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        int n_cols = cols - 1;

        int top = 0;
        int bottom = rows - 1;

        // First Binary Search: Find the correct row
        while (top <= bottom) {
            int row = top + (bottom - top) / 2;
            if (target > matrix[row][n_cols]) {
                top = row + 1;
            } else if (target < matrix[row][0]) {
                bottom = row - 1; // Safe from underflow because it's a signed int
            } else {
                bottom = row; // Lock bottom to the current row and break
                break;
            }
        }

        if (top > bottom) return false;

        // Second Binary Search: Find the element in that row
        int row = bottom; 
        int l = 0;
        int r = n_cols;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target > matrix[row][m]) {
                l = m + 1;
            } else if (target < matrix[row][m]) {
                r = m - 1; // Safe from underflow
            } else {
                return true;
            }
        }

        return false; // Crucial fix: explicitly return false if not found
    }
};
