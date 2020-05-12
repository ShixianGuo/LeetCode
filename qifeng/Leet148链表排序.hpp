#pragma once
#include"entity.h"
using namespace std;

/*
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	//合并，Leetcode21题
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
	//将head切断，使head只有n个元素，返回剩余部分的头节点
	ListNode* cut(ListNode* head, int n) {
		ListNode* p = head;
		while (p && (--n)) {
			p = p->next;
		}
		//如果不够切
		if (!p) return nullptr;
		ListNode* head2 = p->next;
		p->next = nullptr;
		return head2;
	}
	ListNode* tail(ListNode* head) {
		ListNode* p = head;
		while (p->next) {
			p = p->next;
		}
		return p;
	}

	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* p = head;
		//长度
		int length = 0;
		while (p) {
			++length;
			p = p->next;
		}

		ListNode* left, *right, *curr;
		ListNode* vhead = new ListNode(-1);
		vhead->next = head;
		ListNode* pre = vhead;
		for (int step = 1; step <= length; step <<= 1) {
			curr = vhead->next;
			pre = vhead;
			while (curr) {
				left = curr;
				right = cut(left, step);
				curr = cut(right, step);//剩余部分
				//将left和right合并
				pre->next = mergeTwoLists(left, right);
				pre = tail(pre);
			}
		}
		return vhead->next;
	}
};