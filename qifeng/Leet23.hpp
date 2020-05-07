#pragma once
#include"entity.h"
using namespace std;
/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
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
	//思路1：不断找到所有头节点中最小的插入新链表中，k很大搜索很麻烦
	//思路2：循环合并两个链表，合并两链表中不要新建链表
	ListNode* merge(ListNode* head1, ListNode* head2) {
		if (head1 == nullptr&&head2 == nullptr)
			return nullptr;
		if (head1 == nullptr)
			return head2;
		if (head2 == nullptr)
			return head1;
		//确保head1头节点小于head2
		if (head1->val > head2->val)
			swap(head1, head2);
		//开始合并，将head2小的插入到当前节点的前面
		ListNode* pre = head1;
		ListNode* curr = head1->next;
		while (curr != nullptr&&head2 != nullptr) {
			if (head2->val <= curr->val) {
				pre->next = head2;
				head2 = head2->next;
				pre->next->next = curr;

				pre = pre->next;
			}
			else {
				pre = curr;
				curr = curr->next;
			}
		}
		//剩下head2全是大的没合并
		if (head2 != nullptr) {
			pre->next = head2;
		}
		return head1;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int size = lists.size();
		if (size == 0) return nullptr;
		ListNode* ans = lists.front();
		if (size == 1) return ans;
		for (int i = 1; i < size; ++i) {
			ans = merge(ans, lists[i]);
		}
		return ans;
	}
};