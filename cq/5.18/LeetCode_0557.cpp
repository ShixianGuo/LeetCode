class Solution {
    void reverse(string &s,int start,int end){
        while(start<end) swap(s[start++],s[end--]);
    }
public:
    string reverseWords(string s) {
        if(s.size()<2) return s;
        int start=0;
        while(1){
            int end=s.find(' ',start);
            if(end==-1) break;
            reverse(s,start,end-1);
            start=end+1;
        }
        reverse(s,start,s.size()-1);
        return s;
    }
};