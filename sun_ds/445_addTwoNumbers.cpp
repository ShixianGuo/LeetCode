// @File   : 445_addTwoNumbers.cpp
// @Source : https://leetcode-cn.com/problems/add-two-numbers-ii/
// @Title  : 445. 两数相加 II
// @Auther : sun_ds
// @Date   : 2020/5/8

/**  题目描述：
    给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

    你可以假设除了数字 0 之外，这两个数字都不会以零开头。

     

    进阶：

    如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

     

    示例：

    输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 8 -> 0 -> 7

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/add-two-numbers-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.反转链表后执行加操作
 *
 * 2.使用栈存储各位数值，后再加起来。
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
    ListNode* reverse(ListNode* l){
        ListNode* pre = nullptr;
        ListNode* cur = l;
        while(cur!=nullptr){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l11 = reverse(l1);
        ListNode* l22 = reverse(l2);
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int c = 0;
        while(l11!=nullptr||l22!=nullptr||c!=0){
            int a=0;
            if(l11!=nullptr){
                a += l11->val;
                l11 = l11->next;
            }
            if(l22!=nullptr){
                a += l22->val;
                l22 = l22->next;
            }
            a += c;
            c = a/10;
            temp->next = new ListNode(a%10);
            temp = temp->next;
        }
        //再次逆序
        return reverse(dummy->next);
    }
};


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
        stack<int> s1;
        stack<int> s2;
        while(l1!=nullptr){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=nullptr){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* head = nullptr;
        ListNode* temp = nullptr;
        int c=0;
        while(!s1.empty()||!s2.empty()||c!=0){
            int a=0;
            if(!s1.empty()){
                a+=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                a+=s2.top();
                s2.pop();
            }
            a += c;
            c = a/10;
            temp = new ListNode(a%10);
            //逆序拼接。
            temp->next = head;
            head = temp;
        }
        return head;
    }
};



