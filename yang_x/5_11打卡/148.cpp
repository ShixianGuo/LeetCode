/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void catchq(ListNode* head, vector<int> &temp){
        if (head == NULL)
            return;
        temp.push_back(head -> val);
        catchq(head -> next, temp);
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        vector<int> temp;
        catchq(head, temp);
        sort(temp.begin(), temp.end());
        ListNode* ans = head;
        int i = 0;
        while (head != NULL){
            head -> val = temp[i++];
            head = head -> next;
        }
        return ans;
    }
};