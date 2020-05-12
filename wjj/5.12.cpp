Lt13.罗马数字转整数
  int romanToInt(string s) {
      unordered_map<char,int> m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
      int result=0;
      for(int i=1;i<=s.size();i++)
        {
            if(i<s.size()&&m[s[i-1]]<m[s[i]])
                result-=m[s[i-1]];
            else  
                result+=m[s[i-1]];
        }
        return result;
        }
Lt12.整数转罗马数字
 string intToRoman(int num) {
        int a[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string b[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for(int i=0;i<13;i++)
          {
            while(num>=a[i])
               {
                  num-=a[i];
                  res+=b[i];
               }
          }
          return res;
    }
    
Lt32.最长有效括号
int longestValidParentheses(string s) {
    int length= s.size();
    vector<int>dp(length,0);
    int res=0; 
    if(s[0]=='('&&s[1]==')')
        {
            dp[0]=0;
            dp[1]=2;
            res=2;
        }     
      for(int i=2;i<s.size();i++)
         {
           if(s[i]==')'&& s[i-1]=='(')
            {
               dp[i]=dp[i-2]+2;
            }
           else if(s[i]==')'&&s[i-1]==')')
              {
                if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
                  {  
                    if(i-dp[i-1]-2>=0)
                      dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
                    else 
                      dp[i]=dp[i-1]+2;
                  }
              }
            res= res>dp[i] ? res : dp[i];
        }
        return res;
    }
