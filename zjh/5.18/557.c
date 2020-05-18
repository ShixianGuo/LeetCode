class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()){
            return string();
        }
        int i = 0;
        do{
            int j = i;
            while(s[j] && s[j] != ' '){
                ++j;
            }
            for(int m = i, n = j - 1; m < n; ){
                swap(s[m], s[n]);   
                ++m;
                --n;
            }
            i = j;
        } while(s[i++]);
        return s;
    }
};
