#include <print>
class KthLargest {
private:
    std::priority_queue<int, vector<int>, std::greater<int>> q_;
    int k_{-1};
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (size_t i{0}; i < nums.size(); ++i) {
            q_.push(nums[i]);
        }

        while (q_.size() > k) {
            q_.pop();
        }
    }
    
    int add(int val) {
        q_.push(val);
        while (q_.size() > k_) {
            q_.pop();
        }
        return q_.top();    
    }
};
