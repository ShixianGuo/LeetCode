class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0)
            return 0;
        int ans = 0, cnum = 0, pnum = getchar(s[0]);
        ans = pnum;
        for (int i = 1; i < s.length(); ++i){
            cnum = getchar(s[i]);
            if (cnum > pnum)
                ans = ans + cnum - pnum - pnum;
            else
                ans = ans + cnum;
            pnum = cnum;
        }
        return ans;
    }
private:
    int getchar(char Roman){
        switch(Roman){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};