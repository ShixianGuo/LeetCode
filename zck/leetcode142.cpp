#include <iostream>
#include <vector>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

ListNode *detectCycle(ListNode *head){

    unordered_set<ListNode*> s;

    ListNode *cur = head;
    while(cur != NULL){
        if(s.find(cur) == s.end()){
            s.insert(cur);
        }
        else
            return cur;
        cur = cur->next;        
    }
    return NULL;
}

int main(){
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    
    cout << detectCycle(n1)->val << endl;

    return 0;
}