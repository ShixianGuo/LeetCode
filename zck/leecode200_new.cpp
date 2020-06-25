#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<char>>& grid, int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        int row = temp.first;
        int col = temp.second;
        
    }
}

int numIslands(vector<vector<char>>& grid){

}