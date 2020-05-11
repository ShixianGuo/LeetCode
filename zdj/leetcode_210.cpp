#include <vector>
using namespace std;

// DFS
class Solution_1 {
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> tropo;
    bool circle_flag;
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Construct graph
        adj.assign(numCourses, vector<int>());
        for(auto& edge: prerequisites)
            adj[edge[0]].push_back(edge[1]);
        visited.assign(numCourses, 0);
        tropo.reserve(numCourses);
        circle_flag = false;
        for(int i = 0; i < numCourses; i++)
            TropoSort(i);
        if(!circle_flag)
            return tropo;
        else
            return {};
    }

    void TropoSort(int i) {
        if(visited[i] == 2)
            return;
        else if(visited[i] == 1) {
            this->circle_flag = true;
            return;
        }
        else {
            visited[i] = 1;
            for(auto& next: adj[i]) {
                TropoSort(next);
            }
            visited[i] = 2;
            tropo.push_back(i);
            return;
        }
    }
};

// Queue
class Solution_2 {

};