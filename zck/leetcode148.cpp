 #include <iostream>

 using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 

ListNode* sortList(ListNode* head){
    ListNode * res = new ListNode(head->val);

    ListNode *cur = head->next;
    while(cur != NULL){
        if(cur->val < res->val){
            cur->next = res;
            res = cur;
        }
        else{
            ListNode *pre = res;
            ListNode *post = pre->next;
            while(post != NULL && post->val < cur->val){
                pre = pre->next;
                post = pre->next;
            }
            pre->next = cur;
            cur->next = post;
        }
        cur = cur->next;
    }
    return res;
}

int main(){
    ListNode *head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(5);

    ListNode*res = sortList(head);
    ListNode *cur = res;
    while(cur != NULL){
        cout << cur->val << endl;
        cur = cur->next;
    }
    return 0;

}