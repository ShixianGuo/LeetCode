#pragma once
#include"entity.h"
using namespace std;

/*
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		//保证l1是头节点
		if (l1->val > l2->val) {
			swap(l1, l2);
		}
		ListNode* pre = l1;
		ListNode* p1 = l1->next;
		ListNode* p2 = l2;
		while (p1 != nullptr&&p2 != nullptr) {
			if (p2->val < p1->val) {
				pre->next = p2;
				p2 = p2->next;
				pre->next->next = p1;
				pre = pre->next;
			}
			else {
				pre = p1;
				p1 = p1->next;
			}
		}
		if (p2 != nullptr) {
			pre->next = p2;
		}
		return l1;
	}
};