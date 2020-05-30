/*一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。
*/

#include <iostream>
#include <vector>

using namespace std;

int numDecodings(string s){
    if(s[0] == '0')
        return 0;
    int pre = 1, cur = 1;

    for(int i = 1; i < s.size(); i++){
        int temp = cur;

        if(s[i] == '0'){
            if(s[i - 1] == '1' || s[i - 1] == '2'){
                cur = pre;
            }
            else{
                return 0;
            }
        }
        else if(s[i] >= '1' && s[i] <= '6'){
            if(s[i-1] == '1' || s[i-1] == '2'){
                cur = pre + cur;
            }
            else{
                continue; 
            }
            
        }
        //7到9
        else{
            if(s[i-1] == '1'){
                cur = pre + cur;
            }
            else{
                continue;
            }
            
        }
        pre = temp;
    }
    return cur;
}

int main(){
    cout << numDecodings("1001") << endl;

    return 0;
}