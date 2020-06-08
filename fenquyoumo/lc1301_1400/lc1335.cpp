class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int dp[305][15];
        int n=jobDifficulty.size();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=d;j++)
                dp[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=d;j++)
            {
                dp[i][j]=1e6+5;
                int mx=jobDifficulty[i-1];
                if(j==1)
                {
                    for(int k=1;k<=i;k++)
                    {
                        mx=max(mx,jobDifficulty[k-1]);
                    }
                }
                if(i<j)continue;
                if(i==j)
                {
                    dp[i][j]=mx+dp[i-1][j-1];
                    continue;
                }
                for(int k=i-1;k>=1;k--)
                {
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+mx);
                    mx=max(mx,jobDifficulty[k-1]);
                }
            }
        }
        if(dp[n][d]==1e6+5)
            return -1;
        else 
            return dp[n][d];
    }
};