/*
反转一个单链表。
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    //方法3：使用递归
    //明确递归函数返回的是反转后链表的头节点，也就是例子中的5
    ListNode* reverseList(ListNode* head){
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* p=reverseList(head->next);

        //假设p为5->4->3->2->NULL头节点
        head->next->next=head;//2->1
        head->next=nullptr;//1->null
        return p;
    }
    //方法2：在原有空间上进行指针转移
    ListNode* reverseList_2(ListNode* head){
        if(head==nullptr)
            return nullptr;
        ListNode* pre=nullptr;
        ListNode* curr=head;
        ListNode* next=curr->next;
        while(next!=nullptr){
            curr->next=pre;
            //前进
            pre=curr;
            curr=next;
            next=next->next;
        }
        curr->next=pre;
        return curr;
    }
    //方法1：新建链表，遍历旧链表将其元素作为头节点不断插入新链表
    ListNode* reverseList_1(ListNode* head) {
        if(head==nullptr) 
            return nullptr;
        ListNode* newHead=new ListNode(head->val);
        ListNode* curr=head->next;
        while(curr!=nullptr){
            ListNode* node=new ListNode(curr->val);
            node->next=newHead;
            newHead=node;
            curr=curr->next;
        }
        return newHead;
    }
};
