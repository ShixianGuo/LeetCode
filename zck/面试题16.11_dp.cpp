/*
shorter = 1
longer = 2
k = 3
输出： {3,4,5,6}
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> divingBoard(int shorter, int longer, int k){
    if(k == 0)
        return {};
    vector<int> res(k + 1, 0);
    for(int i = 0; i < k + 1; i++){
        res[i] = i * longer + (k - i) * shorter;
    }
    return res;
}

int main(){
    vector<int> res = divingBoard(1, 2, 3);
    for(auto val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}