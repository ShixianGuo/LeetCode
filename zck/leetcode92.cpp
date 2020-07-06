/*92. 反转链表 II
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

*/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *before_head = new ListNode(0);
    ListNode *cur_before = before_head;

    ListNode *mid_head = new ListNode(0);
    

    ListNode *after_head = new ListNode(0);
    ListNode *cur_after = after_head;

    int i = 0;
    while(head != NULL){
        if(i < m - 1){
            cur_before->next = head;
            cur_before = cur_before->next;
        }
        else if(i >= m - 1 && i <= n - 1 ){
            ListNode *temp = new ListNode(head->val);
            temp->next = mid_head->next;
            mid_head->next = temp;
        }
        else{
            cur_after->next = head;
            cur_after = cur_after->next;
        }
        head=head->next;
        i++;
    }
    cur_after->next = NULL;

    cur_before->next = mid_head->next;

    ListNode *cur_mid = mid_head;
    while(cur_mid != NULL){
        cur_mid = cur_mid->next;
    }
    cur_mid->next = after_head->next;

    return before_head->next;
}

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int m = 2, n = 4;
    ListNode *new_head = reverseBetween(head, m, n);
    cout << endl;

    return 0;

}