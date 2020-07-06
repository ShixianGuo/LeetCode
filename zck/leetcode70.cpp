#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    int pre = 1;
    int cur = 1;
    for(int i = 1; i <= n; i++){
        int tmp = cur;
        cur = pre + cur;
        pre = tmp;
    }
    return cur;     
}

int main(){
    cout << climbStairs(1) << endl;
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;

    return 0;
}