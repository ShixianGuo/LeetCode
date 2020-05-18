class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        int mod=1e9+7;
        vector<vector<long long>> dp(L+1,vector<long long>(N+1,0));
        dp[0][0]=1;
        for(int i=1;i<=L;++i)
            for(int j=1;j<=N;++j){
                dp[i][j]+=dp[i-1][j-1]*(N-j+1);
                dp[i][j]+=dp[i-1][j]*max(j-K,0);
                dp[i][j]%=mod;
            }
        return dp[L][N];
    }
};