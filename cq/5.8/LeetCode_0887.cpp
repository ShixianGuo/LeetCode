class Solution
{
    unordered_map<int, int> memo;
    int dp(int K, int N)
    {
        if (K == 1)
            return N;
        if (!N)
            return 0;
        if (memo.find(100 * N + K) != memo.end())
            return memo[100 * N + K];
        int ans = INT_MAX;

        int left=1,right=N;
        while(left<=right){
            int mid=(right-left>>1)+left;  
            int broken=dp(K-1,mid-1);
            int notBroken=dp(K,N-mid);
            if(broken>notBroken){
                right=mid-1;
                ans=min(ans,broken+1);
            }
            else{
                left=mid+1;
                ans=min(ans,notBroken+1);
            }
        }

        memo[100 * N + K] = ans;
        return ans;
    }

public:
    int superEggDrop(int K, int N)
    {
        return dp(K, N);
    }
};