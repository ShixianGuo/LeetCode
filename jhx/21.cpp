/*
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){};
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newList=nullptr;
        ListNode *tail=newList;
        
        while(l1!=nullptr||l2!=nullptr){
            ListNode *waitInsert=nullptr;
            if(l1==nullptr){
                waitInsert=l2;
                l2=l2->next;
            }else if(l2==nullptr){
                waitInsert=l1;
                l1=l1->next;
            }else{
                waitInsert=l1->val<l2->val?l1:l2;
                if(waitInsert==l1){
                    l1=l1->next;
                }else{
                    l2=l2->next;
                }
            }
            if(tail==nullptr){
                newList=waitInsert;
                tail=waitInsert;
            }else{
                tail->next=waitInsert;
                tail=tail->next;
            }
        }
        return newList;    
    }
};

int main(){

}