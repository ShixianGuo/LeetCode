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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int begin, int end) {
        if(begin >= end) return lists[begin];

        int mid = begin + (end - begin) / 2;
        ListNode* leftLists = merge(lists, begin, mid);
        ListNode* rightLists = merge(lists, mid + 1, end);

        return merge2Lists(leftLists, rightLists);
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(-1), *cur = l3;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;

        return l3->next;
    }
};
