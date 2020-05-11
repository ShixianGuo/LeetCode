// @File   : 206_reverseList.cpp
// @Source : https://leetcode-cn.com/problems/reverse-linked-list/
// @Title  : 206. 反转链表
// @Auther : sun_ds
// @Date   : 2020/4/30

/**  题目描述：
    反转一个单链表。

    示例:

    输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL
    进阶:
    你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-linked-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 反序链表
 *
 * 1.迭代
 *  定义pre和cur. while(cur)
 *  将cur的next方向到pre
 *
 */

//迭代
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* temp = cur->next;
            //所有元素指向掉头
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

