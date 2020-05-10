class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
        {
            return 1;
        }
        else if(n == 2)
        {
            return 2;
        }
        else
        {
            vector<int> v{0, 1, 2};
            for(int i = 3; i <= n; i++)
            {
                v.push_back(v[i - 1] + v[i - 2]);
            }
            return *v.rbegin();
        }
    }
};
