#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int find(int x){
        if(x == fa[x])
            return x;
        else
            return find(fa[x]);
    }

    int countComponents(int n, vector<vector<int>>& edges){
        fa.resize(n);
        for(int i = 0; i < n; i++)
            fa[i] = i;
        for(auto edge : edges){
            int f1 = find(edge[0]);
            int f2 = find(edge[1]);
            if(f1 != f2){
                fa[f1] = f2;
                n--;
            }
        }
        return n;
    }
private:
    vector<int> fa;
};