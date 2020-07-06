#include <iostream>
#include <vector>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

//双指针
bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != nullptr) {
        fast = fast->next;
        if(fast != nullptr) {
            fast = fast->next;
        }
        if(fast == slow) {
            return true;
        }
        slow = slow->next;
    }
    return false;
}

//集合
bool hasCycle(ListNode *head){
    unordered_set<ListNode*> s;

    ListNode *cur = head;
    while(cur != NULL){
        if(s.find(cur) == s.end()){
            s.insert(cur);
        } 
        else{
            return true;
        }
        cur = cur->next;
    }
    return false;
}

int main(){
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
    
    cout << hasCycle(n1) << endl;

    return 0;
}
