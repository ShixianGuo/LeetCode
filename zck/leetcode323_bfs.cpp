#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countComponents(int n, vector<vector<int>>& edges){
    vector<vector<int>> adjacents(n);
    for(auto edge : edges){
        adjacents[edge[0]].push_back(edge[1]);
        adjacents[edge[1]].push_back(edge[0]);
    }

    vector<bool> isVisited(n, false);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(isVisited[i])
            continue;
        count++;
        queue<int> q;
        q.push(i);
        isVisited[i] = true;

        while(!q.empty()){
            int index = q.front();
            q.pop();
            isVisited[index] = true;
            for(auto num : adjacents[index])
                if(!isVisited[num])
                    q.push(num);
        }
        
    }
    return count;
}