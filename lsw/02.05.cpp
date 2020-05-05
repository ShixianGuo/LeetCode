class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
       int sum = 0, carry = 0;
        ListNode* dummyHead = new ListNode(0);
        ListNode* head = dummyHead;

        while(l1 || l2)
        {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            head->next = new ListNode((num1 + num2 + carry) % 10);
            carry = (num1 + num2 + carry) / 10;
            head = head->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if(carry) head->next = new ListNode(carry);
        return dummyHead->next;
    }
};
