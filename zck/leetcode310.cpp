#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
    vector<vector<int>> adjacents(n);
    vector<int> indrgrees(n, 0);

    for(auto edge : edges){
        adjacents[edge[0]].push_back(edge[1]);
        adjacents[edge[1]].push_back(edge[0]);
        indrgrees[edge[0]]++;
        indrgrees[edge[1]]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indrgrees[i] == 1){
            q.push(i);
        }
    }
    int cnt = q.size();

    while(n > 2){
        n -= cnt;
        while(cnt--){
            int temp = q.front();
            q.pop();
            indrgrees[temp] = 0;
            for(auto num : adjacents[temp]){
                if(indrgrees[num] == 0)
                    continue;
                indrgrees[num]--;
                if(indrgrees[num] == 1){
                    q.push(num);
                }
            }
        }
        cnt = q.size();
        
    }
    vector<int> res;
    while(!q.empty()){
        res.push_back(q.front());
        q.pop();
    }
    return res;
}

int main(){
    int n = 6;  
    vector<vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    for(auto num : findMinHeightTrees(n, edges)){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}