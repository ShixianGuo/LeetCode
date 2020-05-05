class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int maxLen=0,curLen=0;
        vector<int> pos(128,-1);
        // fill(pos.begin(),pos.end(),-1);
        for(int i=0;i<s.size();++i){
            int preIdx=pos[s[i]];
            if(preIdx<0||i-preIdx>curLen) ++curLen;
            else curLen=i-preIdx;
            pos[s[i]]=i;
            maxLen=max(maxLen,curLen);
        }
        return maxLen;
    }
};