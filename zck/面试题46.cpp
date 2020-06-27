/*
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
*/

#include <iostream>
#include <string>

using namespace std;

int translateNum(int num){
    string s = to_string(num);
    int pre = 1, cur = 1;
    for(int i = 1; i < s.size();  i++){
        if(s[i - 1] == '1' && s[i] >= '0' && s[i] <= '9'){
            int temp = pre + cur;
            pre = cur;
            cur = temp;
            cout << "A" << endl;
        }
        else if(s[i - 1] == '2' && s[i] >= '0' && s[i] <= '5'){
            int temp = pre + cur;
            pre = cur;
            cur = temp;
            cout << "B" << endl;

        }        
        else{
            pre = cur;
            cout << "C" << endl;
        }
    }
    return cur;
}

int main(){
    cout << translateNum(12258) << endl;

    return 0;
}