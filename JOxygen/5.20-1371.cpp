class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> mp(1<<5,-1);
        mp[0] = 0;
        int ans = 0, statu = 0;
        for(int i =0; i < s.size(); i++) {
            switch (s[i]) {
            case 'i':
                statu ^= 1;
                break;
            case 'o':
                statu ^= 1<<1;
                break;
            case 'u':
                statu ^= 1<<2;
                break;
            case 'a':
                statu ^= 1<<3; 
                break;
            case 'e':
                statu ^= 1<<4;
                break;
            }
            if(mp[statu] != -1) {
                ans = max(ans, i-mp[statu]+1);
            } else {
                mp[statu] = i+1;
            }
        }
        return ans;
    }
};