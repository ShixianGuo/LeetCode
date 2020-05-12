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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1||!l2) return l1?l1:l2;
        ListNode *head=new ListNode(-1);
        ListNode *node=head,*p1=l1,*p2=l2;
        while(p1&&p2){
            if(p1->val>p2->val){
                node->next=p2;
                p2=p2->next;
            }
            else{
                node->next=p1;
                p1=p1->next;
            }
            node=node->next;
        }
        if(p1) node->next=p1;
        if(p2) node->next=p2;
        return head->next;
    }
};