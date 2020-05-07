/*

给出两个 非空
的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/



#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int f=0;
        ListNode *newHead=new ListNode(0);
        ListNode *newTail=newHead;
        newTail->val=l1->val+l2->val;
        l1=l1->next;
        l2=l2->next;
        newTail->next=nullptr;
        if(newTail->val>=10){
            newTail->val-=10;
            f++;
        }
        while(l1!=nullptr||l2!=nullptr||f!=0){
            int val=0;
            if(l1!=nullptr){
                val+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                val+=l2->val;
                l2=l2->next;
            }
            val+=f;
            f=0;
            if(val>=10){
                val-=10;
                f++;
            }
            newTail->next=new ListNode(val);
            newTail=newTail->next;
            newTail->next=nullptr;
        }
        return newHead;
        
    }
};
int main(){

}



