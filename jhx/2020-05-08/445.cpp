/*

给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

 

进阶：

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        while(l1!=nullptr){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr){
            s2.push(l2->val);
            l2=l2->next;
        }
        int extra=0;
        while(s1.size()!=0||s2.size()!=0||extra!=0){
            int res=0;
            if(s1.size()!=0){
                int a=s1.top();
                s1.pop();
                res+=a;
            }
            if(s2.size()!=0){
                int a=s2.top();
                s2.pop();
                res+=a;
            }
            res+=extra;
            extra=0;
            if(res>=10){
                extra=1;
                res-=10;
            }
            s3.push(res);
        }
        ListNode *newhead=nullptr;
        ListNode *tail=newhead;
        while(s3.size()!=0){
            if(newhead==nullptr){
                newhead=new ListNode(s3.top());
                s3.pop();
                tail=newhead;
            }else{
                tail->next=new ListNode(s3.top());
                s3.pop();
                tail=tail->next;
            }
        }
        tail->next=nullptr;
        return newhead;
    }
};
int main(){

}