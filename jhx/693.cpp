/*
给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。

示例 1:

输入: 5
输出: True
解释:
5的二进制数是: 101
示例 2:

输入: 7
输出: False
解释:
7的二进制数是: 111
示例 3:

输入: 11
输出: False
解释:
11的二进制数是: 1011
 示例 4:

输入: 10
输出: True
解释:
10的二进制数是: 1010

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-number-with-alternating-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


#include <iostream>
#include <bitset>
#include <string>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> bs(n);
        string s=bs.to_string();
        int i=0;
        for(;s[i]=='0';i++);
        bool Zero=true;
        for(;i<s.size();i++){
            if(s[i]=='0'){
                if(Zero){
                    return false;
                }
                Zero=!Zero;
            }else{
                if(!Zero){
                    return false;
                }
                Zero=!Zero;
            }
        }
        return true;
        
        
    }
};
int main(){
    bitset<32> bs(5);

}
