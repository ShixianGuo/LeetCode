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
        if(!head->next||m==n) return head;
        int changeLen=n-m+1;
        ListNode *preHead=NULL;
        ListNode *res=head;
        while(head&&--m){
            preHead=head;
            head=head->next;
        }
        ListNode *newTail=head;
        ListNode *newHead=NULL;
        ListNode *next=NULL;
        while(head&&changeLen){
            --changeLen;
            next=head->next;
            head->next=newHead;
            newHead=head;
            head=next;
        }
        if(preHead)preHead->next=newHead;
        else res=newHead;
        newTail->next=head;
        return res;
    }
};