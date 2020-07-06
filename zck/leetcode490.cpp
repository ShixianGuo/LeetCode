#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
    vector<vector<bool>> isVisited(maze.size(), vector<bool>(maze[0].size(), false));

    queue<vector<int>> q;
    q.push(start);
    isVisited[start[0]][start[1]] = true;

    while(!q.empty()){
        vector<int> temp = q.front();
        q.pop();
        if(temp[0] == destination[0] && temp[1] == destination[1])
            return true;
        for(auto dir : dirs){
            int x = temp[0] + dir[0];
            int y = temp[1] + dir[1];
            while(x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0){
                x += dir[0];
                y += dir[1];
            }
            if()
        }
    }


}

int main(){

}
