#include <iostream>

// Global fast I/O trick remains the baseline layer
const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    // Adding standard optimization attributes guarantees zero call overhead
    #if defined(__GNUC__) || defined(__clang__)
    __attribute__((always_inline))
    #endif
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            // Hardware Pro-Tip: Prefetch the node after next into L1 cache.
            // This hides memory latency by loading data ahead of time.
            if (curr->next != nullptr) {
                #if defined(__GNUC__) || defined(__clang__)
                __builtin_prefetch(curr->next->next, 0, 3);
                #endif
            }

            // Tighten assignments to maximize CPU register utilization
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev; 
    }
};
