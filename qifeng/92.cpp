/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/


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
    ListNode* tail;
    //将头节点共n个节点的链表，反转，返回头节点
    ListNode* reverse(ListNode* head, int n){
        if(head==nullptr){
            tail=nullptr;
            return nullptr;
        }
        if(head->next==nullptr||n<2){
            tail=head->next;
            return head;
        }
        ListNode* p=reverse(head->next,n-1);
        //仿照206题
        head->next->next=head;
        head->next=tail;
        return p;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr||head->next==nullptr)
            return head;
        if(m<2) 
            return reverse(head, n);
        //已知m小于链表长度，前进到下标为m-1处
        ListNode* node=head;
        for(int i=1;i<m-1;++i){
            node=node->next;
        }
        node->next=reverse(node->next, n-m+1);
        return head;
    }
};