#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d)
            return -1;
        vector<vector<int>> dp(2, vector<int>(jobDifficulty.size(), INT_MAX / 3));
        int predif = 0;
        for(int i = 0; i < jobDifficulty.size(); i++) {
            predif = max(predif, jobDifficulty[i]);
            dp[0][i] = predif;
        }
        for(int i = 1; i < d; i++) {
            for(int j = 0; j < jobDifficulty.size(); j++) {
                predif = jobDifficulty[j];
                for(int k = j; k >= i; k--) {
                    predif = max(predif, jobDifficulty[k]);
                    dp[i % 2][j] = min(dp[i % 2][j], dp[(i-1) % 2][k-1] + predif);
                }
            }
            for(int j = 0; j < jobDifficulty.size(); j++)
                dp[(i-1)%2][j] = INT_MAX / 3;
        }
        return dp[(d-1)%2][jobDifficulty.size()-1];
    }
};

int main() {
    Solution tmp;
    vector<int> test = {1,1,1};
    tmp.minDifficulty(test, 3);
}

