/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
     ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);  
        ListNode *p = &dummyHead,*p1=l1,*p2=l2;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;       
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p=p->next;
        }
        p->next = p1 ? p1 : p2;
        return dummyHead.next;
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
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next=head;
        ListNode *p=head;
        int len=0;
        while(p) {++len;p=p->next;}
        for(int size=1;size<len;size<<=1){
            ListNode *cur=dummyHead.next;
            ListNode *tail=&dummyHead;
            while(cur){
                ListNode *left=cur;
                ListNode *right=cut(left,size);
                cur=cut(right,size);
                tail->next=merge(left,right);
                while(tail->next) tail=tail->next; 
            }
        }
        return dummyHead.next;
    }
};