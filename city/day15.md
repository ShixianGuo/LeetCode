501. 二叉搜索树中的众数

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

    结点左子树中所含结点的值小于等于当前结点的值
    结点右子树中所含结点的值大于等于当前结点的值
    左子树和右子树都是二叉搜索树

例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2

返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）



class Solution {
  public:
	  vector<int>p;
	  map<int, int>vis;
	  void preord(TreeNode* root)
	  {
		  if (root == NULL) {
			  return;
		  }
		  if (root->left != NULL) {
			  preord(root->left);
		  }
		  p.push_back(root->val);
		  vis[root->val]++;
		  if (root->right != NULL) {
			  preord(root->right);
		  }
	  }
	  
	  vector<int> findMode(TreeNode* root) {
		  vector<int>pp;
		  if (root == NULL)
			  return pp;
		  preord(root);
		  int len = p.size();
		  int cnt = 0, temp = 0;

		  for (int i = 0; i < len; i++) {
			  cnt = max(cnt, vis[p[i]]);
		  }
		  for (int i = 0; i < len; i++) {
			  if (vis[p[i]] == cnt) {
                  vis[p[i]] = 0;
				  pp.push_back(p[i]);
			  }
		  }
		  return pp;

	  }
  };















94. 二叉树的中序遍历

给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？
----------------------------------------------------------------------
 class Solution {
  public:
	  vector<int> inorderTraversal(TreeNode* root) {
		  stack<TreeNode*> s;
		  vector<int> v;
		  TreeNode* now = root;
		  while (now != NULL || !s.empty()) {
			  //将当前节点和当前结点的左节点入栈
			  while (now != NULL) {
				  s.push(now);
				  now = now->left;
			  }
			  //从最后一个左节点开始处理，依次将左节点、根节点、右节点的值加入数组
			  now = s.top();
			  s.pop();
			  v.push_back(now->val);
			  now = now->right;
		  }
		  return v;
	  }
  };