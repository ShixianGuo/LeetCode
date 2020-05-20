class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        int neighbor = 0;

        for(int y = 0; y < m; ++y)
            for(int x = 0; x < n; ++x)
                if(grid[y][x] == 1){
                    ++area;
                    if(y > 0 && grid[y - 1][x] == 1) ++neighbor;
                    if(y < m-1 && grid[y + 1][x] == 1) ++neighbor;
                    if(x > 0 && grid[y][x - 1] == 1) ++neighbor;
                    if(x < n-1 && grid[y][x + 1] == 1) ++neighbor;
                }
        return area * 4 - neighbor;
    }
};