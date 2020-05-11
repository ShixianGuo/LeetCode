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
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *pmerge = nullptr;
        if (l1 -> val < l2 -> val){
            pmerge = l1;
            l1 = l1 -> next;
        }
        else{
            pmerge = l2;
            l2 = l2 -> next;
        }
        ListNode *ptemp = pmerge;
        while (l1 != nullptr || l2 != nullptr){
            if (l1 == nullptr){
                ptemp -> next = l2;
                ptemp = ptemp -> next;
                l2 = l2 -> next;
            }
            else if (l2 == nullptr){
                ptemp -> next = l1;
                ptemp = ptemp -> next;
                l1 = l1 -> next;
            }
            else{
                if (l1 -> val < l2 -> val){
                    ptemp -> next = l1;
                    ptemp = ptemp -> next;
                    l1 = l1 -> next;
                }
                else{
                    ptemp -> next = l2;
                    ptemp = ptemp -> next;
                    l2 = l2 -> next;
                }
            }
        }
        return pmerge;
    }
};