class Solution {
public:
    vector<vector<string>> ans;
    vector<string> res;
    bool visc[105],visle[205];
    void dfs(int n,int hav,int nowx)
    {
        if(n==hav)
        {
            ans.push_back(res);
            return ;
        }
        for(int j=0;j<n;j++)
        {
            if(visc[j])continue;
            int le=nowx+j;
            if(visle[le])continue;
            bool ok=false;
            for(int x=max(0,nowx-j),y=max(0,j-nowx);x<n&&y<n;x++,y++)
            {
                if(res[x][y]=='Q')
                {
                    ok=true;
                    break;
                }
            }
            if(ok)continue;
            visc[j]=true;
            visle[le]=true;
            res[nowx][j]='Q';
            dfs(n,hav+1,nowx+1);
            res[nowx][j]='.';
            visc[j]=false;
            visle[le]=false;
        }
        return ;
    }


    vector<vector<string>> solveNQueens(int n) {
        string row="";
        for(int i=0;i<n;i++)
        {
            visc[i]=visle[i]=visle[i+n]=false;
            row+='.';
        }
        for(int i=0;i<n;i++)
            res.push_back(row);
        for(int i=0;i<n;i++)
        {
            visc[i]=true;
            visle[i]=true;
            res[0][i]='Q';
            dfs(n,1,1);
            res[0][i]='.';
            visc[i]=false;
            visle[i]=false;
        }
        return ans;
    }
};