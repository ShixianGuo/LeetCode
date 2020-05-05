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
        // ListNode *dummy = new ListNode(-1), *cur = dummy;
        // int car = 0, sum = 0;
        // while(l1 && l2) {
        //     sum = l1->val + l2->val + car;
        //     ListNode *node = new ListNode(sum % 10);
        //     car = sum / 10;
        //     l1 = l1->next; l2 = l2->next;
        //     cur->next = node;
        //     cur = cur->next;
        // }
        // while(l1) {
        //     sum = l1->val + car;
        //     ListNode *node = new ListNode(sum % 10);
        //     car = sum / 10;
        //     l1 = l1->next; cur->next = node;
        //     cur = cur->next; 
        // }
        // while(l2) {
        //     sum = l2->val + car;
        //     ListNode *node = new ListNode(sum % 10);
        //     car = sum / 10;
        //     l2 = l2->next; cur->next = node;
        //     cur = cur->next; 
        // }
        // if(car != 0) {
        //     ListNode *node = new ListNode(car);
        //     cur->next = node;
        // }
        // return dummy->next;
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int car = 0, sum = 0;
        while (l1 || l2 || car) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + car;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            cur->next = new ListNode(sum % 10);
            car = sum / 10;
            cur = cur->next;
        }
        return dummy->next;
    }
};
