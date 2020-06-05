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
    vector<int> reversePrint(ListNode* head) {
        vector<int> tmp;
        while(head) {
            tmp.push_back(head->val);
            head = head->next;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};