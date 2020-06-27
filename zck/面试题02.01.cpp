/*
 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
*/

#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeDuplicateNodes(ListNode* head){

    if(head == NULL || head->next == NULL)
        return head;

    unordered_set<int> nums;
    
    ListNode* pre = head;
    nums.insert(head->val);

    ListNode* pos = head->next;
    while(pos != NULL){
        if(nums.count(pos->val) != 0){
            pre->next = pos->next;
            pos = pre->next;
        }   
        else{
            nums.insert(pos->val);
            pre = pre->next;
            pos = pre->next;
        }
    }
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(1);

    ListNode* new_head = removeDuplicateNodes(head);
    while(new_head != NULL){
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;

    return 0;
}