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
        if(m==n) return head;
        ListNode *ans,*s,*ss,*p,*t;
        ans=head;
        p=NULL;
        int cnt=1;
        while(head!=NULL)
        {
            t=head->next;
            if(cnt==m)
            {
                ss=p;
                s=head;
            }
            if(cnt>m)
            {
                head->next=p;
            }
            p=head;
            head=t;
            cnt++;
            if(cnt==n)
            {
                s->next=head->next;
                if(ss!=NULL)
                    ss->next=head;
                else
                    ans=head;
            }
            if(cnt>n)break;
        }
        return ans;
    }
};