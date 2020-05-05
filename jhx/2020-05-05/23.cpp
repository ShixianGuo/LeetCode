/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <set>
#include <queue>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


using namespace std;



class Solution {
    struct PtrCmp{

        bool operator()(ListNode *l1,ListNode *l2) const{
            return l1->val>l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*,vector<ListNode*>,PtrCmp> q;
        for(auto i:lists){
            if(i!=nullptr){
                q.push(i);
            }
           
        }
        if(q.size()==0){
            return nullptr;;
        }
        
        ListNode *head=q.top();
        q.pop();
        ListNode *tail=head;
        if(head->next!=nullptr){
            q.push(head->next);
        }
        while(q.size()!=0){
            ListNode *n=q.top();
            q.pop();
            tail->next=n;
            tail=tail->next;
            if(tail->next!=nullptr){
                q.push(tail->next);
            }
        }
        tail->next=nullptr;
        return head;
    }
};

int main(){

}