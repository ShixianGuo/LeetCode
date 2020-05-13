/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        //动态规划
        int size=s.size();
        if(size==0 ||size==1) return 0;
        vector<int> dp(size,0);
        for(int i=1;i<size;++i){
            if(s[i]=='(') dp[i]=0;
            else if(s[i-1]=='('){
                dp[i]=i-2>=0?dp[i-2]+2:2;//要保证不越界
            }
            else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                dp[i]=i-dp[i-1]-2>=0?dp[i-1]+2+dp[i-dp[i-1]-2]:dp[i-1]+2;//要保证不越界
            }
            else{
                dp[i]=0;
            }
        }

        int ans=0;
        for(int i=0;i<size;++i){
            if(ans<dp[i]) ans=dp[i];
        }
        return ans;
    }
};