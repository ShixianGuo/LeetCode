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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL)
           return head;
        
        ListNode* res = head;
        ListNode* post = NULL;
        int count = 1;
        while (count < m) {
            post = head;
            head = head->next;
            count++;
        }
        ListNode* first = head;
        ListNode* pre = head->next;
        while (count < n && pre != NULL) {
            ListNode* t = pre->next;
            pre->next = head;
            head = pre;
            pre = t;
            count++;
        }
        if (post != NULL)
            post->next = head;
        first->next = pre;
 
        return m == 1 ? head : res;
    }
};
