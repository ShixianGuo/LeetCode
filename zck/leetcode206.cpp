#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
ListNode* reverseList(ListNode* head){
    ListNode *pre = NULL;
    ListNode *cur = head;
    while(cur != NULL){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}
*/

ListNode* helper(ListNode*pre, ListNode* head){
    if(head == NULL)
        return pre;
    ListNode*temp = head->next;
    head->next = pre;
    helper(head, temp);
}

ListNode* reverseList(ListNode* head){
    return helper(NULL, head);
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversed_head = reverseList(head);
    while(reversed_head != NULL){
        cout << reversed_head->val << " ";
        reversed_head = reversed_head->next;
    }
    cout << endl;

    return 0;
}
