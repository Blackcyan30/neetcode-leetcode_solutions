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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL; ListNode* nxt = NULL;

        while (cur != NULL) {
            // saving the next node
            nxt = cur->next;
            // reversal of link
            cur->next = prev;
            // prev node should now be cur, since now we are 
            // moving up the list.
            prev = cur;
            cur = nxt;
        }
        head = prev;
        return head;
    }
};
