// @File   : 92_reverseBetween.cpp
// @Source : https://leetcode-cn.com/problems/reverse-linked-list-ii/
// @Title  : 92. 反转链表 II
// @Auther : sun_ds
// @Date   : 2020/4/30

/**  题目描述：
    反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

    说明:
    1 ≤ m ≤ n ≤ 链表长度。

    示例:

    输入: 1->2->3->4->5->NULL, m = 2, n = 4
    输出: 1->4->3->2->5->NULL

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.反转法
 *  re_head指向反转位置m，re_headp指向反转位置m前面的位置。
 *  在m-n区间中，使用pre和cur依次反转指针。
 *  最后将利用re_head和re_headp拼接完成。
 *
 * 2.头插法
 *  pre和cur遍历，直到cur到m位置。
 *  将cur后的值放到前面pre的后面，头插法。
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        if(m==n) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* re_headp = dummy;
        ListNode* re_head = dummy->next;
        for(int i=1;i<m;i++){
            re_headp = re_headp->next;
            re_head = re_head->next;
        }

        ListNode* pre = nullptr;
        ListNode* cur = re_head;
        for(int i=0;i<n-m;i++){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        if(pre!= nullptr){
            re_head->next = cur->next;
            cur->next = pre;
            re_headp->next = cur;
        }

        return dummy->next;
    }
};

//头插法
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        if(m==n) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur = dummy->next;
        //pre为反转前一个节点
        //cur为反转的第一个节点
        for(int i=1;i<m;i++){
            pre = pre->next;
            cur = cur->next;
        }
        //头插法
        //遍历把后面的节点放到前面
        for(int i=0;i<n-m;i++){
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next = pre->next;
            pre->next = temp;
        }

        return dummy->next;
    }
};