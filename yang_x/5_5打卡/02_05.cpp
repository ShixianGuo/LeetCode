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
        ListNode* ans = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* head = ans;
        int car = 0;
        int sum = 0;
        while(p || q || car){
            sum = 0;
            if (p){
                sum += p->val;
                p = p->next;
            }
            if (q){
                sum += q->val;
                q = q->next;
            }
            sum += car;
            car = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            head -> next = temp;
            head = head->next;
        }
        return ans -> next;
    }
};