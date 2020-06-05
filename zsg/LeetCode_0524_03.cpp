#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum(int a, int b) {
        vector<int> va, vb;
        while (a != 0) {
            va.push_back(a % 2);
            a = a / 2;
        }
    }
};

int main() {
    int x = -3;
    cout << x % 2 << x / 2 << endl;
    vector<int> ss;
    ss.push_back(x%2);
    cout << ss.size() << endl;
    return 0;
}