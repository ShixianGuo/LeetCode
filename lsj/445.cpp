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
        stack<int> stack1, stack2;
        while(l1 != NULL) {
            stack1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL) {
            stack2.push(l2->val);
            l2 = l2->next;
        }
        int car = 0,sum = 0;
        ListNode* l3 = NULL;
        while(!stack1.empty() || !stack2.empty() || car != 0) {
            int val1 = 0, val2 = 0;
            if(!stack1.empty()) {
                val1 = stack1.top();
                stack1.pop();
            }
            if(!stack2.empty()) {
                val2 = stack2.top();
                stack2.pop();
            }
            sum = val1 + val2 + car;
            ListNode* cur = new ListNode(sum % 10);
            car = sum / 10;
            cur->next = l3;
            l3 = cur;
        }
        return l3;
    }
};
