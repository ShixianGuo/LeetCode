/*
给定从 0 到 n-1 标号的 n 个结点，和一个无向边列表（每条边以结点对来表示），请编写一个函数用来判断这些边是否能够形成一个合法有效的树结构。

示例 1：

输入: n = 5, 边列表 edges = [[0,1], [0,2], [0,3], [1,4]]
输出: true
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool validTree(int n, vector<vector<int>>& edges){
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for(auto edge : edges){
        graph[edge[0]][edge[1]] = 1;
        graph[edge[1]][edge[0]] = 1;
    }
    vector<bool> isVisited(n, false);

    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        isVisited[temp] = true;
        for(int i = 0; i < n; i++){
            if(graph[temp][i] == 1){
                if(isVisited[i])
                    return false;
                q.push(i);
                graph[temp][i] = 0;
                graph[i][temp] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++)
        if(!isVisited[i])
            return false;
    return true;
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
    cout << validTree(n, edges) << endl;

    return 0;
}


