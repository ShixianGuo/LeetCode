// @File   : 1028_recoverFromPreorder.cpp
// @Source : https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/
// @Title  : 1028. 从先序遍历还原二叉树
// @Auther : sun_ds
// @Date   : 2020/5/13

/**  题目描述：
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
 *
 * 使用栈存储节点和对应节点的深度。
 * 遍历字符串S获取各个节点和对应深度。
 * 比较当前获取节点的深度和栈顶深度之间的关系，进行组合二叉树。
 * 当前深度第一个大于栈顶深度的为栈顶的左孩子。
 * 当前深度等于栈顶深度的为栈顶的兄弟节点，即其父节点的右孩子。
 * 当前深度小于栈顶深度的，需要栈一直出栈，直到当前深度大于栈顶，此时当前节点为栈顶的右孩子。
 *
 */


// https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/solution/cong-xian-xu-bian-li-huan-yuan-er-cha-shu-c-by-hja/
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
    TreeNode* recoverFromPreorder(string S) {
        //pos是一个遍历的全局值
        int pos = 0;
        int depth = 0;
        TreeNode* headNode = GetNextNodeStr(S, pos, depth);
        if (headNode == nullptr) {
            return nullptr;
        }
        //stack存储节点和深度
        std::stack<std::pair<TreeNode*, int>> nodeStack;
        nodeStack.push(std::pair<TreeNode*, int>(headNode, depth));

        TreeNode* curNode = headNode;
        while (!nodeStack.empty() && (curNode != nullptr)) {
            //从S字符串中获取下一个节点和他的深度
            TreeNode* curNode = GetNextNodeStr(S, pos, depth);
            if (curNode == nullptr) {
                break;
            }
            if (depth > nodeStack.top().second) {   //第一个节点深度大于栈顶的节点为栈顶节点的左孩子节点。此时将左孩子节点入栈。
                nodeStack.top().first->left = curNode;
                nodeStack.push(std::pair<TreeNode*, int>(curNode, depth));
            } else if (depth == nodeStack.top().second) {   //当前节点深度等栈顶的节点为栈顶节点的兄弟节点(且为其父节点的右孩子节点)。此时将栈顶出栈，后面栈顶为父节点，将当前右孩子节点入栈。
                nodeStack.pop();
                nodeStack.top().first->right = curNode;
                nodeStack.push(std::pair<TreeNode*, int>(curNode, depth));
            } else {    //当前节点深度小于栈顶节点深度，需要向上 回溯 ？ 直到满足上面两种情况。而深度相等又可以通过pop一个栈顶变成当前深度大于栈顶深度。所以，直到当前深度大于栈顶深度结束循环。当前节点为栈顶节点的右孩子。
                while ((nodeStack.top().second + 1) != depth) {
                    nodeStack.pop();
                }
                nodeStack.top().first->right = curNode;
                nodeStack.push(std::pair<TreeNode*, int>(curNode, depth));
            }
        }

        return headNode;
    }

    TreeNode* GetNextNodeStr(const std::string& str, int& pos, int& depth) {
        depth = 0;
        //统计'-'的个数为当前节点的深度
        while ((pos < str.length()) && (str.at(pos) == '-')) {
            pos++;
            depth++;
        }

        TreeNode* node = nullptr;
        bool isValidValue = false;
        int num = 0;
        while (pos < str.length()) {
            //到下一组'-'结束
            if (str.at(pos) == '-') {
                break;
            }

            if ((str.at(pos) >= '0') && (str.at(pos) <= '9')) {
                num = num * 10 + str.at(pos) - '0';
                isValidValue = true;
            }
            pos++;
        }

        if (isValidValue) {
            node = new TreeNode(num);
        }

        return node;
    }
};



