/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode *s,*nxthead;
        nxthead=head;
        while(head!=NULL)
        {
            s=head;
            head=head->next;
            if(s->next!=NULL&&s->next->next==NULL)
            {
                s->next=NULL;
            }
        }
        s->next=reverseList(nxthead);
        return s;
    }
};
 /*迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *s,*p;
        p=NULL;
        while(head!=NULL)
        {
            s =head->next;
            head->next=p;
            p=head;
            head=s;
        }
        return p;
    }
};
*/