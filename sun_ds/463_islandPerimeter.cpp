// @File   : 463_islandPerimeter.cpp
// @Source : https://leetcode-cn.com/problems/island-perimeter/
// @Title  : 463. 岛屿的周长
// @Auther : sun_ds
// @Date   : 2020/5/20

/**  题目描述：
    给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

    网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

    岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

     

    示例 :

    输入:
    [[0,1,0,0],
     [1,1,1,0],
     [0,1,0,0],
     [1,1,0,0]]

    输出: 16

    解释: 它的周长是下面图片中的 16 个黄色的边：



    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/island-perimeter
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.遍历
 * 一个陆地有四个边。
 * 若左边有相邻的陆地，则当前格子边少一个。
 * 若右边有相邻的陆地，则当前格子边少一个。
 * 若上边有相邻的陆地，则当前格子边少一个。
 * 若下边有相邻的陆地，则当前格子边少一个。
 *
 * 时间复杂度 O(N)
 * 空间复杂度 O(1)
 *
 * 2.dfs
 * 周长由各个边组成，边出现的情况:
 * 2.1 从陆地到水域
 * 2.2 从陆地到越界
 *
 * dfs 的时候：
 * 统计从陆地到水域的个数，即 grid[x][y] = 0;的情况。(前面能递归下来，前一个肯定是陆地。)
 * 统计从陆地到越界的个数，即 x<0||x>=grid.size()||y<0||y>=grid[0].size() 的情况。(前面能递归下来，前一个肯定是陆地。)
 *
 * 最终得到的边的个数就是答案。
 *
 */


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    res += 4;
                    if(i-1>=0 && grid[i-1][j]==1) res -= 1;
                    if(i+1<m && grid[i+1][j]==1) res -= 1;
                    if(j-1>=0 && grid[i][j-1]==1) res -= 1;
                    if(j+1<n && grid[i][j+1]==1) res -= 1;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int dfs(vector<vector<int>>& grid,int x,int y){
        //陆地到边界
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()){
            return 1;
        }
        //陆地到水域
        if(grid[x][y]==0){
            return 1;
        }
        //访问过
        if(grid[x][y]==2){
            return 0;
        }
        grid[x][y] = 2;
        return dfs(grid,x-1,y) + dfs(grid,x+1,y) + dfs(grid,x,y-1) + dfs(grid,x,y+1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    return dfs(grid,i,j);
            }
        }
        return 0;
    }
};

