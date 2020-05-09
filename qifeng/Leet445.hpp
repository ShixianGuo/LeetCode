#pragma once
#include"entity.h"
using namespace std;

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
	//思路1：转化为unsigned int,不行，不知道链表有多长
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr || l2 == nullptr) return nullptr;
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		vector<int> v1;
		vector<int> v2;
		while (l1 != nullptr) {
			v1.push_back(l1->val);
			l1 = l1->next;
		}
		while (l2 != nullptr) {
			v2.push_back(l2->val);
			l2 = l2->next;
		}
		int i = v1.size() - 1;
		int j = v2.size() - 1;
		int carry = 0;
		int num, add1, add2;
		ListNode* curr = nullptr;
		while (i >= 0 || j >= 0||carry>0) {
			add1 = (i < 0) ? 0 : v1[i];
			add2 = (j < 0) ? 0 : v2[j];
			--i; --j;
			num = add1 + add2 + carry;
			carry = 0;
			if (num > 9) {
				num %= 10;
				carry = 1;
			}
			ListNode* head = new ListNode(num);
			head->next = curr;
			//
			curr = head;
		}
		return curr;
	}
};