/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

 

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/

#include <iostream>
#include <vector>

using namespace std;

void backtrack(string s, int start, vector<string>& track, vector<vector<string>>& res){
    if(start >= s.size() && track.size() == 4){
        res.push_back(track);
        return;
    }
    for(int i = start; i < s.size(); i++){
        string temp = s.substr(start, i - start + 1);
        if(temp.size() > 4)
            continue;
        if(stoi(temp) < 0 || stoi(temp) > 255)
            continue;
        track.push_back(temp);
        backtrack(s, i + 1, track, res);
        track.pop_back();
    }
}


int main(){
    string s = "25525511135";

    vector<string> track;
    vector<vector<string>> res;
    backtrack(s, 0, track, res);
    for(auto strs : res)
        for(auto str : strs)
            cout << str << " ";
        cout << endl;
    return 0;
}
