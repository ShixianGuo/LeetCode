#include <iostream>

using namespace std;

int tribonacci(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int tribonacci(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;

    int num1 = 0;
    int num2 = 1;
    int num3 = 1;

    for(int i = 3; i <= n; i++){
        int temp = num1 + num2 + num3;
        num1 = num2; 
        num2 = num3;
        num3 =  temp;
    }
    return num3;
}