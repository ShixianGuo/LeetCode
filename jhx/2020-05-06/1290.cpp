/*
给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <bitset>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s;
        while(head!=nullptr){
            s+=head->val+'0';
            head=head->next;
        }
        bitset<32> i(s);
        
        return i.to_ulong();
    }
};

int main(){
    bitset<32> i("101");
    cout<<i.to_ulong()<<endl;

}

