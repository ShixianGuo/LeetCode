#pragma once
#include"entity.h"
using namespace std;
/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例：
给你这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

说明：
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
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
	int flag = false;
	ListNode* reverse(ListNode* head) {
		//直接反转指针
		ListNode* pre = nullptr;
		ListNode* curr = head;
		ListNode* next = head->next;
		while (next) {
			curr->next = pre;
			//前进
			pre = curr;
			curr = next;
			next = next->next;
		}
		curr->next = pre;
		return curr;
	}
	//cut()，返回切割后第二段链表的头节点
	//注意：不够切和刚好切完返回的都是nullptr
	ListNode* cut(ListNode* head, int n) {
		ListNode* p = head;
		while (p && (--n)) {
			p = p->next;
		}
		//如果不够切，返回nullptr
		if (p == nullptr) {
			flag = true;
			return nullptr;
		}
		//保存后续的链表
		ListNode* head2 = p->next;
		//切断
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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head) return head;
		ListNode* vhead = new ListNode(-1);
		ListNode* pre = vhead;
		ListNode* curr = head;
		while (curr) {
			//切割
			ListNode* head2 = cut(curr, k);
			//如果不够切,最后部分不需要反转
			if (flag) {
				pre->next = curr;
				break;
			}
			//翻转，拼接到pre
			pre->next = reverse(curr);
			//跳转到尾节点，为下次拼接
			pre = tail(pre);
			//curr跳转到下次循环
			curr = head2;
		}
		return vhead->next;
	}
};