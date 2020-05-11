class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        else
        {
            auto first = head;
            auto second = head->next;
            auto third = head->next->next;
            first->next = nullptr;
            while(third)
            {
                second->next = first;
                first = second;
                second = third;
                third = third->next;
            }
            second->next = first;
            return second;
        }
    }
};
