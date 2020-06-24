/*
输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> adjacents(numCourses);
    vector<int> degrees(numCourses);
    queue<int> q;
    for(auto pre : prerequisites){
        adjacents[pre[1]].push_back(pre[0]);
        degrees[pre[0]]++;
    }
    int num = numCourses;
    for(int i = 0; i < numCourses; i++){
        if(degrees[i] == 0){
            q.push(i);
            num--;
        }
    }

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i = 0; i < adjacents[temp].size(); i++){
            if(--degrees[adjacents[temp][i]] == 0){
                q.push(adjacents[temp][i]);
                num--;
            }
        }
    }
    return num == 0;
}

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 2}};
    cout << canFinish(numCourses, prerequisites) << endl;

    return 0;
}
