class Solution {
public:
    int numTrees(int n) {
        // 二叉搜索数的特征，左子树小于根，右子树大于根
        vector<int> dp(n+1, 0);
        dp[0]=1;  // dp[0]初始化为1
        for(int i=1; i<=n; i++)  // 从1...n的二叉搜索数数目
            for(int j=1; j<=i; j++)  // 逐步选用1...n作为根节点
                dp[i]+=dp[j-1]*dp[i-j];  // 左侧j-1个数，右侧i-j个数
        return dp[n]; 
    }
};

//一样没有思路，树太薄弱了，需要加强