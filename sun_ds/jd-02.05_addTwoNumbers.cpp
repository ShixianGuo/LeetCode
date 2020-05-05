// @File   : jd-02.05_addTwoNumbers.cpp
// @Source : https://leetcode-cn.com/problems/sum-lists-lcci/
// @Title  : 面试题 02.05. 链表求和
// @Auther : sun_ds
// @Date   : 2020/5/5

/**  题目描述：
    给定两个用链表表示的整数，每个节点包含一个数位。

    这些数位是反向存放的，也就是个位排在链表首部。

    编写函数对这两个整数求和，并用链表形式返回结果。

     

    示例：

    输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
    输出：2 -> 1 -> 9，即912
    进阶：假设这些数位是正向存放的，请再做一遍。

    示例：

    输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
    输出：9 -> 1 -> 2，即912

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/sum-lists-lcci
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 按位执行加法，其中c为进位。
 * 则，当前位的值为 (l1->val+l2->val+c)%10,下一位进位为c = (l1->val+l2->val+c)/10
 *
 * 如果链表全部正序存放，使用栈或者直接反序链表可以继续使用该方法。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int c=0;
        while(l1||l2||c){
            if(l1){
                c += l1->val;
                l1 = l1->next;
            }
            if(l2){
                c += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(c%10);
            temp = temp->next;
            c /= 10;
        }
        return dummy->next;
    }
};

