#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string pre = countAndSay(n - 1), ans;
        int i = 0;
        for (int j = 0; j <= pre.size(); j++)
        {
            if (pre[i] == pre[j])
            {
                continue;
            }
            else
            {
                ans += to_string(j - i) + pre[i];
                i = j;
                j--;
            }
        }
        return ans;
    }
};


int main() {
    size_t n = 4;
    Solution ss;
    cout << ss.countAndSay(n)<<endl;
    return 0;
}