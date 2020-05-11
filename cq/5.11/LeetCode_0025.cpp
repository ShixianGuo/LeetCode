/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head){
        ListNode *pre=nullptr,*cur=head;
        while(cur){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;cur=next;
        }
        return pre;
    }
    ListNode* cut(ListNode* head,int n){  
        ListNode* p=head;
        while(--n&&p) p=p->next;
        if(!p) return nullptr;
        ListNode* next=p->next;
        p->next=nullptr;
        return next;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode phead(0);
        phead.next= head;
        ListNode *cur=phead.next;
        ListNode *tail=&phead;
        ListNode *p=head;
        int len=0;
        while(p) {++len;p=p->next;}
        while(cur&&k<=len){
            ListNode *pre=cur;
            cur=cut(pre,k);
            tail->next=reverse(pre);
            while(tail->next) tail=tail->next;
            len-=k;
        }
        tail->next=cur;
        return phead.next;
    }
};