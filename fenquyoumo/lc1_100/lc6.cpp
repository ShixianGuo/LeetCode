class Solution {
public:
    string convert(string s, int numRows) {
        int len =s.length();
        if(len==0||numRows==1)return s;
        string rows[min(numRows,len)];
        int x=0,f=0;
        for(int i=0;i<len;i++)
        {
            rows[x]+=s[i];
            if(x==numRows-1)    f=-1;
            if(x==0) f=1;
            x+=f;
        }
        string ans="";
        for(int i=0;i<min(numRows,len);i++)
            ans+=rows[i];
        return ans;
    }
};