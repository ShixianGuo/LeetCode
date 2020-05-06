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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        else if(!l2) return l1;
        else{
            ListNode *t1=l1,*t2=l2;
            int add=t1->val+t2->val;
            int carry=0;
            if(add>9){
                add-=10;carry=1;
            }
            ListNode *node=new ListNode(add);
            ListNode *res=node;
            ListNode *head=node;
            while(t1->next&&t2->next){
                t1=t1->next;t2=t2->next;
                add=t1->val+t2->val+carry;
                if(add>9){
                    add-=10;carry=1;
                }else {carry=0;}
                ListNode *node=new ListNode(add);
                head->next=node;
                head=head->next;
            }
            if(carry){
                if(!t1->next&&!t2->next){
                    ListNode *node=new ListNode(carry);
                    head->next=node;
                }
                while(t1->next){
                    t1=t1->next;
                    add=t1->val+carry;
                    if(add>9){
                        add-=10;carry=1;
                    }else {carry=0;}
                    ListNode *node=new ListNode(add);
                    head->next=node;
                    head=head->next;
                }
                while(t2->next){
                    t2=t2->next;
                    add=t2->val+carry;
                    if(add>9){
                        add-=10;carry=1;
                    }else {carry=0;}
                    ListNode *node=new ListNode(add);
                    head->next=node;
                    head=head->next;
                }   
                if(carry){
                    ListNode *node=new ListNode(carry);
                    head->next=node;
                }
            }
            else{
                if(t1->next){
                    head->next=t1->next;
                }
                if(t2->next){
                    head->next=t2->next;
                }
            }
            return res;
        }
    }
};