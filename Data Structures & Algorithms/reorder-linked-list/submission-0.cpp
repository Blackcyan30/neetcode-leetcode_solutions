/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        vector<ListNode*> linkedList;

        uint16_t n{0};
        while (curr) {
            linkedList.push_back(curr);
            curr = curr->next;     
            n++;
        }

        uint16_t l{0}, r = n - 1;
        while (l < r) {
            linkedList[l]->next = linkedList[r];
            l++;

            linkedList[r]->next = linkedList[l];
            r--;
        }

        linkedList[l]->next = nullptr;
    }
};
