class Solution {
public:
    ListNode* reverse(ListNode* head,int k){
        if(k == 1)
            return head;
        ListNode* cur = reverse(head->next, k - 1);
        head->next->next = head;
        head->next = NULL;
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* p = head;
        while(p && cnt < k) {
            ++cnt;
            p = p->next;
        }
        if(cnt < k)
            return head;
        ListNode* newHead = reverse(head, k);
        head->next = reverseKGroup(p, k);
        return newHead;
    }
};