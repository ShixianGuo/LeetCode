#pragma once
#include"entity.h"
using namespace std;
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* pre = new ListNode(-1);
		ListNode* curr = pre;
		int carry = 0;
		int num = 0, add1 = 0, add2 = 0;
		while (p1 != nullptr || p2 != nullptr) {
			//如果其中一个指针是nullptr，等价与他的val=0
			if (p1 == nullptr) {
				add1 = 0;
				add2 = p2->val;
			}
			else if (p2 == nullptr) {
				add1 = p1->val;
				add2 = 0;
			}
			else {
				add1 = p1->val;
				add2 = p2->val;
			}
			num = add1 + add2 + carry;
			carry = 0;
			if (num > 9) {
				carry = 1;
				num %= 10;
			}
			ListNode* ans = new ListNode(num);
			curr->next = ans;
			curr = ans;
			if (p1 != nullptr) p1 = p1->next;
			if (p2 != nullptr) p2 = p2->next;
		}
		//如果最后还有进位
		if (carry) {
			ListNode* ans = new ListNode(carry);
			curr->next = ans;
		}
		return pre->next;
	}
};