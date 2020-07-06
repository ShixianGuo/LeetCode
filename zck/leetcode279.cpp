#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int numSquares(int n){
    queue<int> q;
    q.push(n);
    unordered_set<int> isVisited;
    int res = 0;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            int temp = q.front();
            q.pop();
            for(int j = 1; j * j <= temp; j++){
                int cur = temp - j * j;
                if(cur == 0)
                    return res + 1;
                if(isVisited.count(cur) != 0)
                    continue;
                q.push(cur);
                isVisited.insert(cur);
                
            }
        }
        res++;
    }
    return res;
}

int main(){
    cout << numSquares(12) << endl;
    cout << numSquares(13) << endl;

    return 0;

}