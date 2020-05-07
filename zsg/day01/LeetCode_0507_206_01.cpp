#include <bits/stdc++.h>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
    int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* head1 = head;
        while (head->next != NULL) {
            head = head->next;
        }
        ListNode* temp_head = head;
        head = NULL;
        temp_head->next = reverseList(head1);
        return temp_head;
    }
};

int main()
{
    ListNode* head;
    head->val = 1;
    head->next->val = 2;
    head->next->next->val = 3;
    head->next->next->next->val = 4;
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;
    Solution ss;
    ListNode* temp = ss.reverseList(head);
    while (temp->next != NULL) {
        cout << temp->val << "  ";
    }
    return 0;
}