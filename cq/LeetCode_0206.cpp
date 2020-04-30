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
    ListNode* reverseList(ListNode* head) {
        //对空链表和只含有一个节点的链表特殊处理
        if(!head||!head->next) return head;

        ListNode* newNode=head;
        ListNode* oldNode=newNode->next;
        ListNode* tmp;
        while(oldNode->next){
            tmp=oldNode->next;
            oldNode->next=newNode;
            newNode=oldNode;oldNode=tmp;
        }
        oldNode->next=newNode;
        head->next=NULL;
        return oldNode;
    }
};