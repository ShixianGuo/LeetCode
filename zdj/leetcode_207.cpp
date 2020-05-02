#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Construct Graph
        adj.assign(numCourses, vector<int>());
        for(auto p = prerequisites.begin(); p != prerequisites.end(); p++) {
            adj[(*p)[0]].push_back((*p)[1]);
        }
        visited.assign(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i))
                return false;
        }
        return true;
    }

    bool dfs(int root) {
        if(visited[root] == 2)
            return true;
        else if(visited[root] == 1)
            return false;
        else {
            visited[root] = 1;
            for(auto p = adj[root].begin(); p != adj[root].end(); p++) {
                if(!dfs(*p))
                    return false;
            }
            visited[root] = 2;
            return true;
        }
    }
};
