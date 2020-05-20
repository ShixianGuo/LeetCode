#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp = l1;
        int count = 0;
        for(tmp = l1; tmp; tmp = tmp->next)
            count++;
        for(tmp = l2; tmp; tmp = tmp->next)
            count--;
        if(count < 0)
            swap(l1, l2);
        ListNode* dummy = new ListNode(0);
        dummy->next = l1;
        ListNode* pre = dummy;
        for(int i = abs(count); i != 0; i--) {
            if(l1->val != 9)
                pre = l1;
            l1 = l1->next;
        }
        while(l1) {
            int tmp = l1->val + l2->val;
            if(tmp > 9) {
                tmp -= 10;
                pre->val += 1;
                pre = pre->next;
                while(pre != l1) {
                    pre->val = 0;
                    pre = pre->next;
                }
                l1->val = tmp;
            }
            else {
                l1->val = tmp;
                if(tmp != 9)
                    pre = l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return dummy->val == 0 ? dummy->next : dummy;
    }
};

