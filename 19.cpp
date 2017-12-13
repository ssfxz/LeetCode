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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        list<ListNode*> buffer;
        ListNode* curr = head;
        
        while(curr != NULL) {
            if (buffer.size() < n + 1) {
                buffer.push_back(curr);
            }
            else {
                buffer.pop_front();
                buffer.push_back(curr);
            }
            curr = curr -> next;
        }
        
        // 如果buffer长度为n而非n+1，即被移除的结点是head
        if (buffer.size() == n) {
            head = head -> next;
        }
        else {
            buffer.front() -> next = buffer.front() -> next -> next;
        }
        
        return head;
    }
};