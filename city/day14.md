617. 合并二叉树

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7

注意: 合并必须从两个树的根节点开始。
--------------先序遍历，一边遍历一边合并-----------------
 class Solution {
  public:
	  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		  if (t1 == NULL)
			  return t2;
		  if (t2 == NULL)
			  return t1;
		  t1->val = t1->val + t2->val;
		  t1->left = mergeTrees(t1->left, t2->left);
		  t1->right = mergeTrees(t1->right, t2->right);
          return t1;
	  }
  };


102. 二叉树的层序遍历

给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]



145. 二叉树的后序遍历

给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？
-----------------利用两个栈，先序遍历的出栈就是后序遍历---------------

 class Solution {
  public:
	  vector<int> postorderTraversal(TreeNode* root) {
		  vector<int>res;
           if (root == NULL)
			  return res;
		  //利用stack1前序遍历二叉树的结点（根、左、右）
		  stack<TreeNode*>stack1;
		  // //再把前序遍历的结果保存在stack2
		  stack<TreeNode*>stack2;
		  stack1.push(root);
		  while (!stack1.empty()) {
			  TreeNode* x = stack1.top();
			  stack1.pop();
			  stack2.push(x);
			  if (x->left != NULL) {
				  stack1.push(x->left);
			  }
			  if (x->right != NULL) {
				  stack1.push(x->right);
			  }
		  }
		  //前序遍历出栈之后就是后序遍历的结果
		  while (!stack2.empty()) {
			  TreeNode* temp = stack2.top();
			  stack2.pop();
			  res.push_back(temp->val);
		  }
		  return res;
	  }
  };