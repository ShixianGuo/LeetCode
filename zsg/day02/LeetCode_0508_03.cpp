#include <bits/stdc++.h>
using namespace std;


 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Solution {
  public:
      // 教科书的写法，添加标志位
      // flag=1：第二次访问（即第一次出栈）
      // flag=2：第三次访问（即第二次出栈，因为第二次访问后会重新入栈）
      struct PostTreeNode {
          TreeNode* TNode;
          int flag;
      };

      vector<int> postorderTraversal(TreeNode* root) {
          if (root == nullptr) {
              return {};
          }
          TreeNode* cur = root;
          vector<int> ans;
          stack<PostTreeNode*> s;
          PostTreeNode* p;
          while (cur != nullptr || !s.empty()) {
              if (cur != nullptr) {
                  p = new PostTreeNode;
                  // 第一次访问（入栈时）不输出
                  p->TNode = cur;
                  p->flag = 1;
                  s.push(p);
                  cur = cur->left;
              }
              else {
                  p = s.top();
                  s.pop();
                  if (p->flag == 1) {
                      // 是第二次访问，即其右子树还没有访问
                      s.push(p);
                      p->flag = 2;
                      cur = p->TNode->right;
                  }
                  else {
                      // 是第三次访问，即其右子树都访问过了
                      ans.push_back(p->TNode->val);
                  }
              }
          }
          return ans;
      }
  };
