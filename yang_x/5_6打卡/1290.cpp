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
        ListNode* cur = head;
        int ans = 0;
        while (cur) {
            ans = ans * 2 + cur->val;
            cur = cur->next;
        }
        return ans;
    }
};
/*
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int cnt = -1;
        vector<int> nums;
        while (head) {
            ++cnt;
            nums.push_back(head->val);
            head = head -> next;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i){
            ans += nums[i] * pow(2, cnt);
            --cnt;
        }
        return ans;
    }
};*/