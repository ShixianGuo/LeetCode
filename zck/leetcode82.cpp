/*82. 删除排序链表中的重复元素 II
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL)
        return NULL;

    ListNode *res = new ListNode(0);
    ListNode *cur = res;

    ListNode *pre = head;
    ListNode *pos = pre->next;
    while(pos != NULL){
        if(pre->val == pos->val){
            int temp = pre->val;
            while(pre->val == temp){
                pre = pre->next;
                if(pre == NULL){
                    pos = NULL;
                    break;
                }
            }
            pos = pre->next;
        }
        else{
            cur->next = pre;
            cur = cur->next;
            pre = pre->next;
            pos = pre->next;
        }
    }
    if(pre != NULL){
        cur->next = pre;
        cur = cur->next;
    }
    cur->next = NULL;

    return res->next;
};

int main(){
    ListNode *head = new ListNode(0);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    
    ListNode *new_head = deleteDuplicates(head);
    while(new_head != NULL){
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;

    return 0;
}

