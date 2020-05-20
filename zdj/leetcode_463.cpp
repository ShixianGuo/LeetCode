#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0)
                    continue;
                if(i - 1 < 0 || grid[i-1][j] != 1)
                    peri++;
                if(j - 1 < 0 || grid[i][j-1] != 1)
                    peri++;
            }
        }
        return peri * 2;
    }
};