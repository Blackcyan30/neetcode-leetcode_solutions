# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        if not list1 and not list2:
            return None

        
        curr1, curr2 = list1, list2
        dummy_head = ListNode(0, 0)
        new_curr = dummy_head
        while curr1 and curr2:
            val1, val2 = curr1.val, curr2.val
            if val1 < val2:
                new_curr.next = ListNode(val1)
                curr1 = curr1.next
            else:
                new_curr.next = ListNode(val2)
                curr2 = curr2.next
            new_curr = new_curr.next
        
        while curr1:
            new_curr.next = curr1
            curr1 = curr1.next
            new_curr = new_curr.next

        while curr2:
            new_curr.next = curr2
            curr2 = curr2.next
            new_curr = new_curr.next


        return dummy_head.next