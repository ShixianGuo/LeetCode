#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
     ListNode* sortList(ListNode* head) {
         if (head == NULL || head->next == NULL)
         {
             return head;
         }
         ListNode* pmid;
         ListNode* mid = head;
         ListNode* trail = head;
         while (trail && trail->next)
         {
             pmid = mid;
             mid = mid->next;
             trail = trail->next->next;
         }
         pmid->next = NULL;

         return twoWayMerge(sortList(head), sortList(mid));
     }

     ListNode* twoWayMerge(ListNode* l1, ListNode* l2) {
         ListNode header(-1);
         ListNode* p = &header;
         while (l1 && l2)
         {
             if (l1->val < l2->val)
             {
                 p->next = l1;
                 l1 = l1->next;
             }
             else
             {
                 p->next = l2;
                 l2 = l2->next;
             }
             p = p->next;
         }

         p->next = l1 == NULL ? l2 : l1;

         return header.next;
     }
 };
