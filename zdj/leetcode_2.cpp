using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int len = 0;
        ListNode* tmp = l1;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        tmp = l2;
        while (tmp) {
            len--;
            tmp = tmp->next;
        }
        if(len < 0) {
            tmp = l2;
            l2 = l1;
            l1 = tmp;
        }
        ListNode* result = l1;
        ListNode* l1_pre = nullptr;
        while(l1 && l2) {
            l1->val += (l2->val + carry);
            if(l1->val > 9) {
                l1->val = l1->val % 10;
                carry = 1;
            }
            else
                carry = 0;
            l1_pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            l1->val += carry;
            if(l1->val > 9) {
                l1->val = l1->val % 10;
                carry = 1;
            }
            else
                carry = 0;
            l1_pre = l1;
            l1 = l1->next;
        }
        if(carry != 0)
            l1_pre->next = new ListNode(carry);
        return result;
    }
};

