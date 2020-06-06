/*给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *helper(vector<int> &nums, int left, int right){
    if(left > right)
        return nullptr;
        
    int root_index = (left + right) / 2;
    TreeNode *root = new TreeNode(nums[root_index]);
    root->left = helper(nums, left, root_index - 1);
    root->right = helper(nums, root_index + 1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}
