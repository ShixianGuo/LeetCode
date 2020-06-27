#include <iostream>
#include <vector>

using namespace std;

int multiply(int A, int B) {
    if(A > B)
        swap(A, B);
    if(A == 1)
        return B;
    return multiply(A - 1, B) + B;
}

int main(){
    cout << multiply(1, 10) << endl;

    cout << multiply(3, 4) << endl;

    cout << multiply(5, 3) << endl;

    return 0;
}