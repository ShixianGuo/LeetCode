#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//4->2->1->3

ListNode* insertionSortList(ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *res = new ListNode(0);
    res->next = new ListNode(head->val);
    head = head->next;

    while(head != NULL){
        if(head->val < res->next->val){
            ListNode *temp = new ListNode(head->val);
            temp->next = res->next;
            res->next = temp;
        }
        else{
            ListNode *pre = res->next;
            ListNode *post = pre->next;
            while(post != NULL && post->val < head->val){
                pre = pre->next;
                post = pre->next;
            }
            ListNode *temp = new ListNode(head->val);
            if(post == NULL){
                pre->next = temp;
            }
            else{
                pre->next = temp;
                temp->next = post;
            }
        }
        head = head->next;
        
    }
    return res->next;
}

int main(){
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(1);
    ListNode *n4 = new ListNode(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    ListNode *head = insertionSortList(n1);
    
    cout << head->val << endl;
    cout << head->next->val << endl;
    cout << head->next->next->val << endl;
    cout << head->next->next->next->val << endl;

    return 0;
}
