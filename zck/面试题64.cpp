#include <iostream>
#include <vector>

using namespace std;

int sumNums(int n){
    n && (n += sumNums(n-1));
    return n;
}

int main(){
    cout << sumNums(3) << endl;

    return 0;
}
