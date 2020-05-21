class Solution {
    vector<vector<int>> dp;
public:
    int solve(vector<int>& jobDifficulty, int pos, int restd) {
        --restd;
        if(dp[pos][restd] != -1){
            return dp[pos][restd];
        }
        int Min = INT_MAX;
        int Max = -1;
        if(restd == 0){
            for(int i = jobDifficulty.size() - 1; i >= pos; --i){
                Max = max(Max, jobDifficulty[i]);
                dp[i][restd] = Max;
            }
            return dp[pos][restd];
        }
        for(int i = pos; i < jobDifficulty.size() - restd; ++i){
            Max = max(Max, jobDifficulty[i]);
            int tmp = Max + solve(jobDifficulty, i + 1, restd);
            Min = min(Min, tmp);
        }
        dp[pos][restd] = Min;
        return Min;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d){
            return -1;
        }
        dp = vector<vector<int>>(jobDifficulty.size(), vector<int>(d, -1));
        return solve(jobDifficulty, 0, d);
    }
};
