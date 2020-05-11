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
    ListNode* reverse(ListNode* head){ // 三个指针来实现
        ListNode* new_head = head;
        ListNode* next = head->next;
        head = next->next;
        new_head->next = NULL;
        while(head != NULL){
            next->next = new_head;
            new_head = next;
            next = head;
            head = head->next;
        }
        next->next = new_head;
        return next;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        return reverse(head);
    }
};