#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){

    int m = maze.size();
    int n = maze[0].size();

    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
    
    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    isVisited[start[0]][start[1]] = true;
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        int row = temp.first;
        int col =  temp.second;
        cout << row << " " << col << endl;

        if(row == destination[0] && col == destination[1])
            return true;
        isVisited[row][col] = true;
        while(row + 1 < m && maze[row + 1][col] == 0){
            row += 1;
        }
        if(isVisited[row][col] == false){
            q.push({row, col});
            isVisited[row][col] = true;
        }
        row = temp.first;
        col = temp.second;
        while(row - 1 >= 0 && maze[row - 1][col] == 0){
            row--;
        }
        if(isVisited[row][col] == false){
            q.push({row, col});
            isVisited[row][col] = true;
        }
        row = temp.first;
        col = temp.second;
        while(col + 1 < n && maze[row][col + 1] == 0){
            col++;
        }
        if(isVisited[row][col] == false){
            q.push({row, col});
            isVisited[row][col] = true;
        }
        row = temp.first;
        col = temp.second;
        while(col - 1 >= 0 && maze[row][col - 1] == 0){
            col--;
        }
        if(isVisited[row][col] == false){
            q.push({row, col});
            isVisited[row][col] = true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> maze = {{0,0,1,0,0},
                                {0,0,0,0,0},
                                {0,0,0,1,0},
                                {1,1,0,1,1},
                                {0,0,0,0,0}};
    vector<int> start = {0,4};
    vector<int> destination = {3, 2};

    cout << hasPath(maze, start, destination) << endl;

    return 0;
}