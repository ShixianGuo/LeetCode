#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* res;
        
        if (l1->val <= l2->val) {
            res = l1;
            l1 = l1->next;
            res->next = NULL;
        }
        else {
            res = l2;
            l2 = l2->next;
            res->next = NULL;
        }
        ListNode* head = res;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                res->next = l1;
                l1 = l1->next;
                res = res->next;
                res->next = NULL;
            }
            else {
                res->next = l2;
                l2 = l2->next;
                res = res->next;
                res->next = NULL;
            }
        }
        while (l1 != NULL) {
                res->next = l1;
                l1 = l1->next;
                res = res->next;
                res->next = NULL;
        }
        while (l2 != NULL) {
                res->next = l2;
                l2 = l2->next;
                res = res->next;
                res->next = NULL;
        }
        return head;
    }
};