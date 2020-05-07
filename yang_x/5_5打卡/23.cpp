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
        int list_size = lists.size();
        map<int, int> temp;
        for (int i = 0; i < list_size; ++i){
            ListNode* head = lists[i];
            while(head){
                temp[head->val]++;
                head = head -> next;
            }
        }
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        for (auto i : temp){
            while(i.second > 0){
                ListNode* list_temp = new ListNode(i.first);
                head -> next = list_temp;
                head = head -> next;
                i.second--;
            }
        }
        return ans -> next;
    }
};