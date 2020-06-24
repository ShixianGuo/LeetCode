/*
输入: 2, [[1,0]] 
输出: [0,1]
解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
    vector<int> degrees(numCourses);
    vector<vector<int>> adjacents(numCourses);
    vector<int> res;

    for(auto pre : prerequisites){
        adjacents[pre[1]].push_back(pre[0]);
        degrees[pre[0]]++;
    }

    queue<int> q;
    for(int i = 0; i < degrees.size();  i++){
        if(degrees[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        res.push_back(temp);
        for(auto n : adjacents[temp]){
            --degrees[n];
            if(degrees[n] == 0){
                q.push(n);
            }
        }
    }
    if(res.size() != numCourses)
        return {};
    return res;
}

int main(){
    
}