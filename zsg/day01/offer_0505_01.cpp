#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        vector<int> ss;
        while (pHead->next != NULL) {
            ss.push_back(pHead->val);
            if (core(ss, pHead->val)) {
                return pHead->next;
            }
            pHead = pHead->next;
        }
        return NULL;
    }
    bool core(vector<int> ss, int x) {
        if (ss.size() < 2) return false;
        for (int i = 0; i < ss.size(); i++) {
            if (ss[i] == x) return true;
        }
        return false;
    }
};