// @File   : 25_reverseKGroup.cpp
// @Source : https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
// @Title  : 25. K 个一组翻转链表
// @Auther : sun_ds
// @Date   : 2020/5/11

/**  题目描述：
    给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

    k 是一个正整数，它的值小于或等于链表的长度。

    如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

     

    示例：

    给你这个链表：1->2->3->4->5

    当 k = 2 时，应当返回: 2->1->4->3->5

    当 k = 3 时，应当返回: 3->2->1->4->5

     

    说明：

    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 借助反转一段链表程序
 *
 *
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
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* end = dummy;
        while(end!=nullptr){
            for(int i=0;i<k&&end!=nullptr;i++) end=end->next;
            if(end==nullptr) break;
            ListNode* start = pre->next;
            ListNode* next = end->next;
            //断开
            end->next = nullptr;
            pre->next = reverse(start);
            //反转后的尾是start了。接到next
            start->next = next;
            //更新pre和end位置=start也即是反转后的尾
            pre = start;
            end = start;
        }
        return dummy->next;
    }
};
