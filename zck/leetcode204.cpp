#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPrime(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int countPrimes(int n){
    int count = 0;
    for(int num = 2; num < n; num++)
        if(isPrime(num))
            count++;
    return count;
}

int main(){
    cout << countPrimes(10) << endl;

    return 0;
}