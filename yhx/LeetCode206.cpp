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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
           return head;
        ListNode* pre = head->next;
        head->next = NULL;
        while (pre != NULL) {
            ListNode* t = pre->next;
            pre->next = head;
            head = pre;
            pre = t;
        }
        return head;
    }
};
