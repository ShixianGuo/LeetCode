/*
我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。

 

示例 1：



输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
示例 2：



输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]
示例 3：



输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]
 

提示：

原始树中的节点数介于 1 和 1000 之间。
每个节点的值介于 1 和 10 ^ 9 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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
    //思路1：暴力法，递归，每个递归生成根节点，然后遍历string找出左子树范围和右子树范围
    //思路2：仿照先序遍历的迭代方式
    pair<TreeNode*, int>getNodePair(const string& str, int& begin){
        int size=str.size();
        pair<TreeNode*, int> ans={nullptr, -1};
        //如果到底就返回nullptr
        if(begin>=size) return ans;
        //先获得深度
        int depth=0;
        while(begin<size&&str[begin]=='-'){
            ++begin;
            ++depth;
        }
        ans.second=depth;
        //此时begin对应数字
        int num=0;
        while(begin<size&&str[begin]!='-'){
            num=num*10+str[begin]-'0';
            ++begin;
        }
        ans.first=new TreeNode(num);
        //此时begin对应'-'或者末尾超出边界
        return ans;
    }

    TreeNode* recoverFromPreorder(string S) {
        if(S.empty()) return nullptr;
        stack<pair<TreeNode*, int>> nodeStack;
        int begin=0;
        auto rootPair=getNodePair(S, begin);
        nodeStack.push(rootPair);
        while(!nodeStack.empty()){
            auto nodePair=getNodePair(S, begin);
            //如果取出nullptr，说明到了终点
            if(nodePair.first==nullptr){
                break;
            }
            //将新节点的深度和栈顶节点比较
            //如果相等，说明是同等级，右节点
            if(nodePair.second==nodeStack.top().second){
                //下一个栈顶是父节点
                nodeStack.pop();
                nodeStack.top().first->right=nodePair.first;
                nodeStack.push(nodePair);
            }
            else if(nodePair.second>nodeStack.top().second){
                //如果新节点更大，说明是左子节点
                nodeStack.top().first->left=nodePair.first;
                nodeStack.push(nodePair);
            }
            else{
                //如果新节点深度更小,不断pop找到兄弟节点，再找到父节点
                while(nodePair.second<nodeStack.top().second){
                    nodeStack.pop();
                }
                nodeStack.pop();
                nodeStack.top().first->right=nodePair.first;
                nodeStack.push(nodePair);
            }
        }
        return rootPair.first;
    }
};