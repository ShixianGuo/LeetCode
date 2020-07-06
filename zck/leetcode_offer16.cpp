/*
栈空间超过
*/



#include <iostream>

using namespace std;

double pow(double x, int n){
    if(n == 0)
        return 1;
    return pow(x, n - 1) * x;
}
double myPow(double x, int n) {
    if(n < 0)
        return double(1 / pow(x, -n));
    else
        return double(pow(x, n));
}

int main(){
    cout << myPow(2.000, -2) << endl;

    return 0;
}