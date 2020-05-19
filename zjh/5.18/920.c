class Solution {
public:
    int solve(vector<vector<long>> &dp, int N, int restN, int restL, int K){
        if(dp[restN][restL]){
            return dp[restN][restL];
        }
        if(restN == restL){
            long res = 1;
            for(int i = 2; i <= restN; ++i){
                res *= i;
                res %= (1000 * 1000 * 1000 + 7);
            }
            dp[restN][restL] = res;
            return res;
        }
        long res = 0;
        if(restN > 0){
            res += (long)restN * solve(dp, N, restN - 1, restL - 1, K) % (1000 * 1000 * 1000 + 7);
        }
        long ano = N - K - restN;
        if(ano > 0){
            res += ano * solve(dp, N, restN, restL - 1, K) % (1000 * 1000 * 1000 + 7);
        }
        res %= (1000 * 1000 * 1000 + 7);
        dp[restN][restL] = res;
        return res;
    }

    int numMusicPlaylists(int N, int L, int K) {
        long res = 1;
        int restN = N;
        for(int i = 0; i < K; ++i){
            res *= restN;
            res %= (1000 * 1000 * 1000 + 7);
            --restN;
            --L;
        }
        auto dp = vector<vector<long>>(N + 1, vector<long>(L + 1));
        return res * solve(dp, N, restN, L, K) % (1000 * 1000 * 1000 + 7);
    }
};
