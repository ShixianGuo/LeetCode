class Solution {
public:
    bool vis[105][105];
    bool check(int i,int j,int k)
    {
        int res=i%10+(i/10)%10+(i/100)%10;
        res+=j%10+(j/10)%10+(j/100)%10;
        return (res<=k);
    }

    int movingCount(int m, int n, int k) {
        int ans=0;
        vis[0][0]=true;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0){ans++;continue;}
                if(check(i,j,k))
                {
                    if((i>0&&vis[i-1][j])||(j>0&&vis[i][j-1]))
                    {   
                        //cout<<i<<" "<<j<<endl;
                        ans++;
                        vis[i][j]=true;
                    }
                    else if(i==0&&vis[i][j-1])
                    {
                        //cout<<i<<" "<<j<<endl;
                        ans++;
                        vis[i][j]=true;
                    }
                    else if(j==0&&vis[i-1][j])
                    {
                        //cout<<i<<" "<<j<<endl;
                        ans++;
                        vis[i][j]=true;
                    }
                }
            }
        }
        return ans;
    }
};