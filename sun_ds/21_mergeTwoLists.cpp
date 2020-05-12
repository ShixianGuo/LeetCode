// @File   : 21_mergeTwoLists.cpp
// @Source : https://leetcode-cn.com/problems/merge-two-sorted-lists/
// @Title  : 21. 合并两个有序链表
// @Auther : sun_ds
// @Date   : 2020/5/11

/**  题目描述：
    将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

    示例：

    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 合并有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(l1||l2){
            if(l1==nullptr){
                temp->next = l2;
                l2 = l2->next;
            }else if(l2==nullptr){
                temp->next = l1;
                l1 = l1->next;
            }else{
                if(l1->val < l2->val){
                    temp->next = l1;
                    l1 = l1->next;
                }else{
                    temp->next = l2;
                    l2 = l2->next;
                }
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};

