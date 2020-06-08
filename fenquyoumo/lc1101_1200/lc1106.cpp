class Solution {
public:
    bool parseBoolExpr(string str) {
        //cout<<str<<endl;
        int len=str.length();
        if(len==1&&(str[0]=='t'||str[0]=='&'))
        {
            //cout<<str[0]<<endl;
            if(str[0]=='t')return true;
            else return false;
        }
        else
        {
            //!
            if(str[0]=='!')
            {
                int left=1;
                for(int i=2;i<len;i++)
                {
                    if(str[i]==')')
                    {
                        left--;
                        if(left==0)
                        {
                            return !parseBoolExpr(str.substr(2,i-2));
                        }
                    }
                    if(str[i]=='(')
                        left++;
                }
            }
            //&
            if(str[0]=='&')
            {
                int left=1;
                bool res=true;
                int lst=2;
                for(int i=2;i<len;i++)
                {
                    if(left==1&&str[i]==',')
                    {
                        res&=parseBoolExpr(str.substr(lst,i-lst));
                        lst=i+1;
                    }
                    if(str[i]==')')
                    {
                        left--;
                        if(left==0)
                        {
                            res&=parseBoolExpr(str.substr(lst,i-lst));
                            break;
                        }
                    }
                    if(str[i]=='(')
                        left++;
                }
                return res;
            }
            //|
            if(str[0]=='|')
            {
                int left=1;
                bool res=false;
                int lst=2;
                for(int i=2;i<len;i++)
                {
                    if(left==1&&str[i]==',')
                    {
                        res|=parseBoolExpr(str.substr(lst,i-lst));
                        lst=i+1;
                    }
                    if(str[i]==')')
                    {
                        left--;
                        if(left==0)
                        {
                            res|=parseBoolExpr(str.substr(lst,i-lst));
                            break;
                        }
                    }
                    if(str[i]=='(')
                        left++;
                }
                return res;
            }
        }
        return NULL;
    }
};