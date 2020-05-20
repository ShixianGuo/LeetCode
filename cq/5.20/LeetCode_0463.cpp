class Solution {
    int cnt1=0;//1的个数
    int cnt2=0;//相连1的个数
    bool isVaild(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return 0;
        return 1;
    }
    void dfs(vector<vector<int>>& grid,int& cnt1,int& cnt2,int i,int j){
        if(!isVaild(grid,i,j)) return;
        if(grid[i][j]){
            cnt1++;
            if(isVaild(grid,i,j+1)&&grid[i][j+1]) cnt2++;
            if(isVaild(grid,i,j-1)&&grid[i][j-1]) cnt2++;
            if(isVaild(grid,i+1,j)&&grid[i+1][j]) cnt2++;
            if(isVaild(grid,i-1,j)&&grid[i-1][j]) cnt2++;
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                dfs(grid,cnt1,cnt2,i,j);
        return 4*cnt1-cnt2;
    }
};