class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (d > n)
            return -1;
        vector<vector<int>> dp(d, vector<int>(n, INT_MAX));
        int preMax=0;
        //初始化
        for(int i=0;i<n;++i){
            preMax=max(preMax,jobDifficulty[i]);
            dp[0][i]=preMax;
        }
        for(int i=1;i<d;++i)
            for(int j=i;j<n;++j){
                preMax=jobDifficulty[j];
                for(int k=j;k>=i;--k){
                    preMax=max(preMax,jobDifficulty[k]);
                    dp[i][j]=min(dp[i][j],dp[i-1][k-1]+preMax);
                }
            }
        return dp[d-1][n-1];
    }
};