#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head){
    ListNode* pre = NULL;
    ListNode* cur = head;
    while(cur != NULL){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode* ret = reverseList(head);
    cout << ret->val << endl;
    cout << ret->next->val << endl;
    cout << ret->next->next->val << endl;

    cout << int(ret == head) << endl;
    return 0;
}
