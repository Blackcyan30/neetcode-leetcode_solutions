#include <vector>

// 1. Blazing Fast I/O Bootstrapping
// This runs globally before main() execution starts.
const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        const int n = static_cast<int>(temperatures.size());
        
        // 2. The Return Vector
        std::vector<int> res(n, 0);
        
        // 3. Ultra Low-Latency Stack Allocation
        // LeetCode constraints limit size to 100,000.
        // Stacking a raw array avoids expensive heap allocation / tracking overhead completely.
        int index_stack[100005]; 
        int stack_ptr = 0; // Acts as our ultra-fast stack size tracker

        // 4. Cache Raw Pointer References
        // Bypasses vector indexing wrapper overhead, giving pure pointer arithmetic speed.
        const int* const temp_ptr = temperatures.data();
        int* const res_ptr = res.data();

        for (int i = 0; i != n; ++i) {
            const int current_temp = temp_ptr[i];
            
            // Unrolled step-back logic utilizing direct memory lookups
            while (stack_ptr > 0 && current_temp > temp_ptr[index_stack[stack_ptr - 1]]) {
                --stack_ptr; // Pop
                const int prev_idx = index_stack[stack_ptr];
                res_ptr[prev_idx] = i - prev_idx;
            }
            
            // Push directly onto the raw pointer array
            index_stack[stack_ptr] = i;
            ++stack_ptr;
        }
        
        return res;
    }
};
