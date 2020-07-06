#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0;
    ListNode *curA = headA;
    ListNode *curB = headB;
    while (curA){
        lenA++;
        curA = curA->next;
    }
    while(curB){
        lenB++;
        curB = curB->next;
    }

    if(lenA - lenB > 0){
        int step = lenA - lenB;
        while(step > 0){
            headA = headA->next;
            step--;
        }
    }
    else{
        int step = lenB - lenA;
        while(step > 0){
            headB = headB->next;
            step--;
        }
    }
    while(headA != headB && headA && headB){
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
    
}

int main(){
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = new ListNode(8);
    headB->next->next->next->next = new ListNode(4);
    headB->next->next->next->next->next = new ListNode(5);

    ListNode *commonNode = getIntersectionNode(headA, headB);
    
    cout << commonNode->val << endl;

    return 0;
} 


