leetcode 7.整数反转
class Solution {
public:
    int reverse(int x) {
        bool is=true;
        if(x<0)
           is=false;
        int result=0;
        int i=0;
        int count=0;
        int num=x;
        while(x)
        { 
            int num=x%10;
            if(result>INT_MAX/10||(result==INT_MAX/10&&num>7)) return 0;
            if(result<INT_MIN/10||(result==INT_MIN/10&&num<-8)) return 0;
            result=result*10+x%10;
            x/=10;
            i++;
        }
      return result;
    }
};
题解：整数反转，即取余10,得到末尾累加，并每次做乘10处理，注意判断范围，(2147483647~-2147483648)
leetcode 98.验证二叉搜索树
class Solution {
public:
    long num=LONG_MIN; 
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
           return true;
         bool a=isValidBST(root->left);
         if(num>=root->val)
            return false;
          else
             num=root->val;
        bool b=isValidBST(root->right);
        return a&&b;
    }
};
题解：判断二叉树是否为搜索二叉树其实就是中序遍历，保证中序遍历序列为递增序列，且需要判断左子树与右子树。
leetcode 41.缺失的第一个正数
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==1&&nums[0]==1)
          return 2;
          bool is=false;
          for(int i=0;i<nums.size();i++)
            {
              if(nums[i]==1)
                  {is=true;
                  break;}   
            }
            if(is==false)
               return 1;
         for(int i=0;i<nums.size();i++)
           {
               if(nums[i]<=0||nums[i]>nums.size())
                  nums[i]=1;
           }
          for(int i=0;i<nums.size();i++)
            {
                if(fabs(nums[i])==nums.size())
                   nums[0]=-fabs(nums[0]);
                else  
                   nums[fabs(nums[i])]=-fabs(nums[fabs(nums[i])]);
            }
          for(int i=1;i<nums.size();i++)
            {
                if(nums[i]>0)
                   return i;
            }
          if(nums[0]>0)
            return nums.size();
          return nums.size()+1;
    }
};
题解：先判断是否有1，若无1则直接输出1。
     再将所有负数以及大于数组size的位置改为1。
     利用数字本身正负号做bitmap，nums[fabs([nums[i]])]=-fabs(nums[fabs(nums[i])]),对于nums.size(),用nums[0]做处理。
     遍历数组，大于0的位置则为缺失的第一个正数。     
     
      
      
      
      
