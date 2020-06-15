/*
*编写一个函数来查找字符串数组中的最长公共前缀。
*如果不存在公共前缀，返回空字符串 ""。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string commonPrefix(string s1, string s2){
    string res = "";
    int i = 0;
    while(s1[i] == s2[i] && i < min(s1.size(), s2.size())){
        res += s1[i];
        i++;
    }
    return res;
}
string longestCommonPrefix(vector<string>& strs){
    if(strs.size() == 0)
        return "";
        
    string temp = strs[0];

    for(int i = 1; i < strs.size(); i++){
        temp = commonPrefix(temp, strs[i]);
    }
    return temp;
}

int main(){

    vector<string> strs = {"dog","racecar","car"}; 
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}