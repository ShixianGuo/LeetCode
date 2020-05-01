    ListNode* reverseList(ListNode* head) {
        ListNode *p;
        for(p=NULL; head; swap(head,p))
            swap(p,head->next);
        return p;
    }