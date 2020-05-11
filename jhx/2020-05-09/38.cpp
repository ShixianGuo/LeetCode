/*

输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

搜索也可，但是不想写hhh太蠢了
*/



#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <stack>
using namespace std;


class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        sort(s.begin(),s.end());
        do{
            res.push_back(s);
        }while(next_permutation(s.begin(),s.end()));
        return res;
    }
};