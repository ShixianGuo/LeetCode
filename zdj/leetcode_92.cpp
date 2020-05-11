#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)
            return head;
        int i = 0;
        ListNode* pre_head = NULL;
        ListNode* tail = head;
        for(i = 1; i < m; i++)
            pre_head = tail;
            tail = tail->next;

        ListNode* cur = tail;
        ListNode* pre = NULL;
        ListNode* next;
        while(cur && i <= n) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            i++;
        }
        if(pre_head)
            pre_head->next = pre;
        else
            head = pre;
        tail->next = next;
        return head;
    }
};

int main() {
    Solution tmp;
    ListNode* head = new ListNode(5);
    tmp.reverseBetween(head, 1, 1);

}
