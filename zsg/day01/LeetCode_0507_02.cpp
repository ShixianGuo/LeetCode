#include <bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* pre0, * cur0;
        int count = 1;
        while (cur != NULL && count <= n) {
            //当cur为m时
            if (count == m) {
                //在头结点，则
                pre0 = pre;
                cur0 = cur;
                //常规操作
                pre = cur;
                cur = cur->next;
            }
            else if (count > m&& count < n)//当cur在m，n之间时
            {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            else if (count == n) {
                //将cur的next指向pre
                ListNode* temp = cur->next;
                cur->next = pre;
                //将pre0的next指向第n元素
                if (pre0 == NULL) head = cur;
                else pre0->next = cur;
                //将指向m的cur0的next指向n后的第一个元素
                cur0->next = temp;
                //更新pre和cur
                pre = cur0;
                cur = temp;
            }
            else {
                //常规处理
                pre = cur;
                cur = cur->next;
            }
            ++count;
        }
        return head;
    }
};