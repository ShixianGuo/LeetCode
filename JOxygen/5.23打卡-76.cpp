class Solution {
public:
    string minWindow(string s, string t) {
        int start = -1, len = INT_MAX, left = 0, right = 0,  n = s.size(), tsize = 0, wsize = 0;
        int wmap[128]{};
        int tmap[128]{};
        for(char c : t) {
            if(tmap[c] == 0) tsize++;
            tmap[c]++;
        }
        while(right < n) {
            char c = s[right++];
            if(tmap[c]) {
                wmap[c]++;
                if(wmap[c]==tmap[c]) wsize++;
            }
            //if window size == target size: valid;
            // start left move
            while (tsize == wsize && left < right) {
                if(right - left < len) {
                    len = right - left;
                    start = left;
                }
                char delc = s[left++];
                if(tmap[delc]) {
                    wmap[delc]--;
                    if(wmap[delc] == tmap[delc]-1) wsize--;
                }
            }
        }
        return start>-1? s.substr(start,len):"";
    }
};