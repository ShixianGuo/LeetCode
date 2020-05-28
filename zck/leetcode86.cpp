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
    ListNode* partition(ListNode* head, int x) {
        ListNode *cur = head;
        ListNode *lower_head = new ListNode(0);
        ListNode *lower = lower_head;

        ListNode *higher_head = new ListNode(0);
        ListNode *higher = higher_head;

        while(cur != NULL){
            if(cur->val < x){
                lower->next = cur;
                lower = lower->next;
            }
            else{
                higher->next = cur;
                higher = higher->next;
            }
            cur=cur->next;
        }
        higher->next = NULL;
        lower->next = higher_head->next;
        return lower_head->next;
    }
};