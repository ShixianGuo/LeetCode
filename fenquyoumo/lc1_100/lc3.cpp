class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int len=s.length();
        int l=0,r=0,ans=0;
        for(int i=0;i<len;i++)
        {
            if(st.find(s[i])==st.end())
            {
                st.insert(s[i]);
                r++;
                ans=max(ans,r-l);
            }
            else
            {
                r++;
                while(s[l]!=s[i])
                {
                    st.erase(s[l]);
                    l++;
                }
                l++;
                ans=max(ans,r-l);
            }
        }
        return ans;
    }
};