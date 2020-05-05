// @File   : 23_mergeKLists.cpp
// @Source : https://leetcode-cn.com/problems/merge-k-sorted-lists/
// @Title  : 23. 合并K个排序链表
// @Auther : sun_ds
// @Date   : 2020/5/5

/**  题目描述：
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

/**
 *
 * 合并K个排序链表
 *
 * 使用长度等于链表个数的优先队列。
 * 优先队列中存储每个链表中的头节点。
 * 维护了一个小顶堆，每次从优先队列中取出k个链表中的最小值，并将该链表的下一个头节点放入优先队列中。
 * 当所有元素都被取出后，完成任务。
 *
 * 时间复杂度 O(N*log(K)) N为所有链表节点的总个数，k为链表的个数
 * 空间复杂度 O(K)
 *
 *
 *
 */

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
    struct cmp{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        //各链表的头节点插入优先队列
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                q.push(lists[i]);
            }
        }
        //每次从堆顶取节点，并将该节点下一个节点入堆(如果有的话）
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!q.empty()){
            ListNode* t = q.top();
            q.pop();
            if(t->next!=nullptr){
                q.push(t->next);
            }
            temp->next = t;
            temp = temp->next;
        }
        return dummy->next;
    }
};

