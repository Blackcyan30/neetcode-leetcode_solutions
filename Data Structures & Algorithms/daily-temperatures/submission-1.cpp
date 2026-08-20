#include <vector>

using std::vector;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = static_cast<int>(temperatures.size());
        vector<int> res(n, 0);
        
        vector<int> index_stack;
        index_stack.reserve(n); 

        for (int i = 0; i < n; ++i) {
            while (!index_stack.empty() && temperatures[i] > temperatures[index_stack.back()]) {
                int stack_idx = index_stack.back(); // Get top
                index_stack.pop_back();            // Pop top
                res[stack_idx] = i - stack_idx;
            }
            index_stack.push_back(i);
        }
        
        return res;
    }
};
