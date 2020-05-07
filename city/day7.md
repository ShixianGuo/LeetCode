给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321

 示例 2:

输入: -123
输出: -321

示例 3:

输入: 120
输出: 21

注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer

****************处理溢出的时候有些烦*******************
class Solution {
public:
    typedef long long ll;
    int reverse(int x) {
        int flag=0;
        ll xx=x;
        if(xx<0)
        {
            flag=1;
            xx=xx*-1;
        }
        ll ans=0;
        while(xx)
        {
            int temp=xx%10;
            xx=xx/10;
            ans=ans*10+temp;
        }
        if(flag)
            ans=ans*-1;
        if(ans>pow(2,31)-1||ans<pow(-2,31))
            return 0;
        else
            return ans;
    }
};



98. 验证二叉搜索树

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

示例 1:

输入:
    2
   / \
  1   3
输出: true

示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6


**************中序遍历输出二叉树是一个递增的序列******************
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	typedef long long ll;
	vector<ll>p;
	bool check()
	{
		int flag = 1;
		int len = p.size();
		for (int i = 0; i < len-1; i++)
		{
			if (p[i] >= p[i + 1])
			{
				flag = 0;
				break;
			}
		}
		return flag;
	}
	void Inorder(TreeNode* root)
	{
		if (root->left != NULL) //输出左节点
			Inorder(root->left);
		p.push_back(root->val);
		if (root->right != NULL)
			Inorder(root->right);//输出右节点
	}
	bool isValidBST(TreeNode* root) {
        if (root == NULL)
			return true;
		Inorder(root);
		return check();
	}

};

41. 缺失的第一个正数

给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

 

示例 1:

输入: [1,2,0]
输出: 3

示例 2:

输入: [3,4,-1,1]
输出: 2

示例 3:

输入: [7,8,9,11,12]
输出: 1

 

提示：

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) return i + 1;
		}
		return n + 1;
	}
};