class Solution {
public:
    int romanToInt(string s) {
        char roman[7]={'I','V','X','L','C','D','M'};
        int num[7]={1,5,10,50,100,500,1000};
        int res=0;
        for(int i=0;i<s.size();++i){
            for(int j=0;j<7;++j)
                if(s[i]==roman[j]) res+=num[j];
        }
        for(int i=0;i<s.size()-1;++i){
            if(s[i]=='I'&&(s[i+1]=='V'||s[i+1]=='X')) res-=2;
            if(s[i]=='X'&&(s[i+1]=='L'||s[i+1]=='C')) res-=20;
            if(s[i]=='C'&&(s[i+1]=='D'||s[i+1]=='M')) res-=200;
        }
        return res;
    }
};