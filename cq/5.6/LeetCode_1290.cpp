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
    int getDecimalValue(ListNode* head) {
        ListNode* node=head;
        int res=0;
        while(node->next){
            res=(res+node->val)<<1;
            node=node->next;
        }
        res=res+node->val;
        return res;
    }
};