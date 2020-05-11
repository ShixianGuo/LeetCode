class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
       ListNode* pre =head->next;
       ListNode* sre =head;
       head->next =NULL;
      while(pre !=NULL)
      {
        head =pre;
        pre = head->next;
        head->next= sre;
        sre =head;
      }
      return head;
    }
};