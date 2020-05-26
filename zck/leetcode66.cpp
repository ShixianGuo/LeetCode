/*给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits){
    digits.back() += 1;
    int n = digits.size();
    for(int i = n - 1; i > 0; i--){
        if(digits[i] > 9){
            digits[i-1] += digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
    }
    if(digits[0] > 9){
        int temp = digits[0] / 10;
        digits[0] = digits[0] % 10;
        digits.insert(digits.begin(), temp);
    }
    return digits;
}

int main(){
    vector<int> digits = {9,9,9};
    vector<int> res = plusOne(digits);
    for(auto num : res)
        cout << num << " ";
    cout << endl;

    return 0;
}