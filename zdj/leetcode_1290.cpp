
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* tmp = head;
        while(tmp) {
            tmp = tmp->next;
            len++;
        }
        int result = 0;
        int pos = 0;
        while(head) {
            result += head->val * pow(2, len - pos - 1);
            pos++;
            head = head->next;
        }
        return result;
    }
};
