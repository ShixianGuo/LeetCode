class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode * first=head;
        for(int i=0;i<m-2;i++)
        {
            head=head->next;
        }
        ListNode * TP =head;
        ListNode * CP =TP->next;
        ListNode * pre=NULL;
        ListNode * scr=NULL;
        head =head->next;
        scr = pre =head;
        if(head->next==NULL)
          {
              if(m>1)
            return first; 
              else{
                TP->next=NULL;
                CP->next=TP;
                return CP;
               }
          }
        for(int i=0;i<(n-m+1);i++)
        {
            pre=head->next;
            head->next=scr;
            scr =head;
            head=pre;
        }
        if(m>1)
        {
            CP->next=head;
            TP->next=scr;
            return first;
        }
        return first;

    }
};