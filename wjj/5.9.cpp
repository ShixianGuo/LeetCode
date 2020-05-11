面试题42
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          int sum=0;
          int result=INT_MIN;
          for(int i=0;i<nums.size();i++)
            {   if(sum<0)
                    sum=nums[i];
                else
                 sum+=nums[i];
                if(sum>result)
                   result=sum;
            }
            return result;
    }
};
题解：为正一直累加，为负从当前数开始，每次更新max值即可。

面试题38
class Solution {
public:
    vector<string> permutation(string s) {
      vector<string> result;
      process( s,0,result);
      return result;
    }
    void process(string s,int i,vector<string>&result)
    {
         if(i==s.size())
           result.push_back(s);
         bool vis[26];
         memset(vis,0,26);
         for(int j=i;j<s.length();j++)
          {
              if(!vis[s[j]-'a'])
              {
               vis[s[j]-'a']=true;
               swap(s,i,j);
               process(s,i+1,result);
               swap(s,i,j);
              }
          }
    }
    void swap(string &s,int i,int j)
    {
        char c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
};
题解：对每一位与后面位置进行交换即可。

面试题51：
public:
    int reversePairs(vector<int>& nums) {
      if(nums.size()<=0)
        return 0;
      return process(nums,0,nums.size()-1);
    }
    int process(vector<int>&num,int l,int r)
    {
       if(l==r)
         return 0;
        
          int m=(l+r)>>1;
         return  process(num,l,m)+process(num,m+1,r) +merge(num,l,m,r);
         
    }
    int merge(vector<int>&num,int l,int m,int r)
    {
        int p1=l;
        int p2=m+1;
        int help[r-l+1];
        int i=0;
        int res=0;
        while(p1<=m&&p2<=r)
        {
                 help[i++]=num[p1]>num[p2]?num[p2]:num[p1];
                 if(num[p1]>num[p2])
                     {
                        res+=m-p1+1;
                        p2++;
                     }
                else
                    p1++;
        }
        while(p1<=m)
           help[i++]=num[p1++];
        while(p2<=r)
           help[i++]=num[p2++];
        for(int j=0;j<i;j++)
          num[l+j]=help[j];
    return res;
    }
};
题解：归并排序
