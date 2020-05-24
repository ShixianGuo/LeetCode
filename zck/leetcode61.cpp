#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* cur = head;
    int len = 0;
    while(cur != NULL){
        len++;
        cur = cur->next;
    }
    k = k % len;
    if(k == 0)
        return head;

    cur = head;
    int index = 0;
    ListNode *head2;
    while(cur != NULL){
        if(index == len - k - 1){
            head2 = cur->next;
            cur->next = NULL;
            break;
        }
        index++;
        cur = cur->next;
    }

    ListNode *cur2 = head2;
    while(cur2->next != NULL){
        cur2 = cur2->next;
    }

    cur2->next = head;

    return head2;
}

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 1;
    ListNode *head2 = rotateRight(head, k);
    while(head2 != NULL){
        cout << head2->val << " ";
        head2 = head2->next;
    }
    return 0;
}