class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(char c : s) {
            if(c != ' ') {
                ans+=c;
            } else {
                ans+="%20";
            }
        }
        return ans;
    }
};