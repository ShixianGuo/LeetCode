// @File   : 148_sortList.cpp
// @Source : https://leetcode-cn.com/problems/sort-list/
// @Title  : 148. 排序链表
// @Auther : sun_ds
// @Date   : 2020/5/11

/**  题目描述：
    在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

    示例 1:

    输入: 4->2->1->3
    输出: 1->2->3->4
    示例 2:

    输入: -1->5->3->4->0
    输出: -1->0->3->4->5

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/sort-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 使用快慢指针确定链表的重点。
 * 切分后使用二路归并。
 * 最终得到排序链表。
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //获得中点，并切分成两段
        ListNode* h2 = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(h2);
        //合并阶段
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(left!=NULL&&right!=NULL){
            if(left->val<right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        temp->next = left == NULL ? right : left;
        return dummy->next;
    }
};

