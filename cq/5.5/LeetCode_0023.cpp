/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* mergeTwoLists(ListNode* a,ListNode* b){
        if(!a||!b) return a?a:b;
        ListNode *head=new ListNode(-1);
        ListNode *node=head,*p1=a,*p2=b;
        while(p1&&p2){
            if(p1->val>p2->val){
                node->next=p2;
                p2=p2->next;
            }
            else{
                node->next=p1;
                p1=p1->next;
            }
            node=node->next;
        }
        node->next=p1?p1:p2;
        return head->next;
    }
    ListNode* merge(vector<ListNode*>& lists,int left,int right){
        if(left==right) return lists[left];
        int mid=(left+right)>>1;
        return mergeTwoLists(merge(lists,left,mid),merge(lists,mid+1,right));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return merge(lists,0,lists.size()-1);
    }
};