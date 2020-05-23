#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pPrev = dummy;
        ListNode* pCurr = head;
        while (pCurr != nullptr) {
            int i = 0;
            while (i++ < k && pCurr != nullptr) {
                pCurr = pCurr->next;
            }
            if (i != k + 1) break;

            ListNode* pTemp = pPrev->next;
            pPrev->next = reverse(pTemp,pCurr);
            pPrev = pTemp;
        }
        return dummy->next;
    }
    ListNode* reverse(ListNode* head,ListNode* tail) {
        if (head == NULL) return head;
        ListNode* pre = tail;
        ListNode* cur = head;
        while (cur != tail) {
            ListNode* temp = cur->next;
            if (pre == tail) {
                cur->next = tail;
            }
            else {
                cur->next = pre;
            }
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};