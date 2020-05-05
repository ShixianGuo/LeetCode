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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* temphead = pHead;
        ListNode* p1 = pHead;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        if (p2 == NULL) {
            return temphead;
        }
        if (p2->next == NULL) {
            if (p1->val == p2->val) {
                return nullptr;
            }
            else {
                return temphead;
            }
        }
        while (p3 != NULL||p2!=NULL) {
            if (p2->val == p3->val) {
                p2 = p3->next;
                p3 = p2->next;
                p1->next = p2;
            }
            else {
                p1 = p1->next;
                p2 = p1->next;
                p3 = p2->next;
            }
           
        }
        return temphead;
    }
};

//尾插法建立单链表
ListNode* Creat_LinkList_R()
{
    int x;
    ListNode* head, * p, * tail;//tail是尾指针
    head = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL)
        return head;
    head->next = NULL;
    tail = head; //一开始尾指针指向头指针的位置
    cout << "请输入要录入的数以0结束" << endl;
    cin >> x;
    while (x != 0)
    {
        p = (ListNode*)malloc(sizeof(ListNode));
        if (p == NULL)
            return head;
        p->val = x;
        tail->next = p; //将p插入到尾节点的后面
        tail = p;   //修改尾节点的指向
        tail->next = NULL;    //将尾节点的指针域修改为空
        cin >> x;
    }
    return head;

}
int main() {
    ListNode* pHead = Creat_LinkList_R();//尾插法
    Solution xx;
    xx.deleteDuplication(pHead);
    return 0;
}