class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
         ListNode *preNNode=nullptr, *LastNode=nullptr;
         // 创建dummmy节点，让head指向dummy
         ListNode *dummy = new ListNode(-1);
         dummy->next = head;
         head = dummy;
        
        // 找到开始的前一个节点
         int i=1;
         for(; i<m; i++)
         {
             head=head->next;
         }
         
         // 保存翻转链表的前一个节点preNNode 和 翻转链表的最后一个节点LastNode
         preNNode = head;
         head=head->next;
         LastNode = head;
         // 和链表翻转一样
         ListNode* prev = nullptr;
         ListNode* next = nullptr;
         for(;i<=n && head; i++)
         {
             next = head->next;
             head->next = prev;
             prev = head;
             head = next;
         }
         // 之前保存的preNNode指向翻转的头结点prev, 翻转的最后一个节点LastNode指向next节点
         preNNode->next = prev;
         LastNode->next = next;
         return dummy->next;
    }
};
