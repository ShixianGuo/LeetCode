/*
*输入：19
*输出：true
*解释：
*12 + 92 = 82
*82 + 22 = 68
*62 + 82 = 100
*12 + 02 + 02 = 1
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isHappy(int n){
    unordered_set<string> st;
    string s;
    while(n != 1){
        s = to_string(n);
        sort(s.begin(), s.end());
        if(st.count(s) != 0)
            return false;
        st.insert(s);
        n = 0;
        for(auto c : s){
            int temp = int(c - '0');
            n += temp * temp;
        }
    }
    return true;
}

int main(){
    cout << isHappy(19) << endl;

    return 0;
}