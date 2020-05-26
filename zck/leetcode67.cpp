/*给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b){
    if(a.size() < b.size())
        swap(a, b);
    int n1 = a.size();
    int n2 = b.size();

    for(int i = 0; i < n2; i++){
        a[n1 - i - 1] = (a[n1 - i - 1] - '0') + (b[n2 - i - 1] - '0') + '0';
    }
    //cout << a << endl;
    int t = 0;
    for(int i = 0; i < n1; i++){
        int temp = a[n1 - i - 1] - '0' + t;
        a[n1-i-1]  = temp % 2 + '0';
        t = temp / 2;
        
    }
    //cout << a << endl;
    if(t != 0){
        string res = "";
        while(t != 0){
            res += t % 2 + '0';
            t = t / 2;
        }
        //cout << res << endl;
        a = res + a;
    }
    return a;
}


int main(){
    string a = "1010";
    string b = "1011";
    cout <<  addBinary(a, b) << endl;
    return 0;
}