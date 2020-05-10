class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
            return 1;
        vector<int> res(n+1, 1);
        for(int i = 2; i < n + 1; i++)
            res[i] = res[i-1] + res[i-2];  
        return res[n];
    }
};