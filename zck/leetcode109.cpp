/*给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *helper(ListNode *head){
    int len = 0;
    ListNode *cur = head;
    while(cur != NULL)
        len++;
    
    int i = 0;
    cur = head;
    while(i < len / 2){
        cur = cur->next;
    }

    TreeNode *root = new TreeNode(cur->val);

    ListNode *right = cur->next;
    cur = NULL;
    ListNode *left = head;
    
    root->left = helper(left); 
    root->right = helper(right);
    
    return root;
}

TreeNode* generate(ListNode *head){
    return helper(head);
}
