class Solution {
    bool scanInteger(string s,int &idx){
        if(idx>=s.size()) return 0;
        if(s[idx]=='+'||s[idx]=='-') ++idx;
        return scanUnsignedInteger(s,idx);
    }
    bool scanUnsignedInteger(string s,int &idx){
        int before=idx;
        while(idx<s.size()&&s[idx]>='0'&&s[idx]<='9') ++idx;
        return idx>before;
    }
public:
    bool isNumber(string s) {
        if(!s.size()) return 0;
        int idx=0;
        while(s[idx]==' ') ++idx;
        bool flag=scanInteger(s,idx);
        if(s[idx]=='.'){
            ++idx;
            flag=scanUnsignedInteger(s,idx)||flag;
        }
        if(s[idx]=='e'||s[idx]=='E'){
            ++idx;
            flag=flag&&scanInteger(s,idx);
        }
        while(s[idx]==' ') ++idx;
        return flag&&idx==s.size();
    }
};