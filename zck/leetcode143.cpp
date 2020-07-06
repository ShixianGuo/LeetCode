/*给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

void reorderList(ListNode* head){
    if(head == NULL || head->next == NULL)
        return;
    ListNode *pre = head;
    ListNode *post = head->next;

    while(post->next != NULL){
        pre = pre->next;
        post = pre->next;
    }

    ListNode *temp = new ListNode(post->val);
    pre->next = NULL;
    
    temp->next = head->next;
    head->next = temp;

    reorderList(head->next->next);
}

int main(){
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    reorderList(n1);
    
    cout << n1->val<< endl;
    cout << n1->next->val << endl;
    cout << n3->val << endl;
    cout << n4->val << endl;

    return 0;
}