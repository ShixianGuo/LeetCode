class Solution {
public:
    int myAtoi(string str) {
        if(str=="") return 0;
        int flag=0;  //正负
        long long ans=0;
        int idx=0;
        while(str[idx]==' ') ++idx;
        if(idx>=str.size()) return 0;

        if(isdigit(str[idx])){
            for(int i=idx;i<str.size();++i){
                if(isdigit(str[i])){
                    ans=ans*10+str[i]-'0';
                    if(ans>INT_MAX) return INT_MAX;
                } 
                else break;
            }
        }
        else if(str[idx]=='+'){
            ++idx;
            if(idx<str.size()&&isdigit(str[idx]))
                for(int i=idx;i<str.size();++i){
                    if(isdigit(str[i])){
                        ans=ans*10+str[i]-'0';
                        if(ans>INT_MAX) return INT_MAX;
                    }
                    else break;
                }
            else return 0;
        }
        else if(str[idx]=='-'){
            flag=1;
            ++idx;
            if(idx<str.size()&&isdigit(str[idx]))
                for(int i=idx;i<str.size();++i){
                    if(isdigit(str[i])){
                        ans=ans*10+str[i]-'0';
                        if(ans>(long long)INT_MAX+1) return INT_MIN;
                    }
                    else break;
                }
            else return 0;
        }
        else return 0;
        if(flag) return (int)-ans;
        else return (int)ans;
    }
};