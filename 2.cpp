/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * head = new ListNode(0);
        ListNode * curr = head;
        while (l1 != NULL || l2 != NULL || carry) {
            int l1_val = l1 == NULL ? 0 : l1 -> val;
            int l2_val = l2 == NULL ? 0 : l2 -> val;
            int val = l1_val + l2_val + carry;
            curr -> next = new ListNode(val % 10);
            carry = val / 10;
            l1 = l1 == NULL ? NULL : l1 -> next;
            l2 = l2 == NULL ? NULL : l2 -> next;
            curr = curr -> next;
        }
        return head -> next;
    }
};
