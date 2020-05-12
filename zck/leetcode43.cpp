#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2){
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int n1 = num1.size(), n2 = num2.size();
    vector<int> ans(n1 + n2, 0);
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    for(int k = 0; k < n1 + n2; k++){
        if(ans[k] > 9){
            int temp = ans[k];
            ans[k] = temp % 10;
            ans[k + 1] += temp / 10;
        }
    }

    string res = "";
    for(auto x : ans){
        res += char(x + '0');
    }
    reverse(res.begin(), res.end());
    int i;
    for(i = 0; i < res.size(); i++){
        if(res[i] != '0'){
            break;
        }
    }
    res = res.substr(i);
    return res;
}


int main(){
    string num1 = "123";
    string num2 = "456";
    cout << multiply(num1, num2) << endl;

    return 0;

}