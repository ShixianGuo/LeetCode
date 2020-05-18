class Solution {
public:
    string longestPalindrome(string s) {
        string str=s;
        int p[2005];
        s="$#";//预处理，使得无论原字符串长度是奇还是偶。都能够变成奇数，这样一定有中心点
        for(int i=0;i<(int)str.length();i++) {
            s+=str[i];
            s+='#';
        }//初始后 形如“$#1#2#3#4#5#”

        int mx=0,id=0,reslen=0,resid=0;//mx 用于记录当前的最大回文串的（最右端+1），id用于存储当前最大回文串的中心点

        for(int i=1;i<(int)s.size();i++) {//枚举中心点i
            /*如果当前枚举的中心点在mx范围内 ；利用在mx内部对称，i的对称点j（=id-（i-id））=2*id-i；
            分为两种情况：一种是以对称点j为中心点的最大回文串在以id为中心点的回文串内部，所以同样的i的最大回文串不可能超过mx
            另一种是 j为中心点的回文串超出了以i为中心点的范围，所以i的最小长度就是mx-i
                */
            if(i<mx) p[i]=min(p[2*id-i],mx-i);
            else p[i]=1;//如果不小于mx，则i的回文串半径初始化为1（本身）
            while(s[i+p[i]]==s[i-p[i]]) p[i]++;//以i为中心点，不断扩展半径p[i]
            if(i+p[i]>mx) mx=i+p[i],id=i;//如果当前操作的回文串的最右端大于mx，更新mx
            if(p[i]>reslen) 
            {
                reslen=p[i];//更新最大长度
                resid=i;
            }
        }
        string ans="";
        for(int j=resid-reslen+1;j<resid+reslen;j++)
        {
            if(s[j]!='#'&&s[j]!='$')ans+=s[j];
        }
        return ans;
    }
};