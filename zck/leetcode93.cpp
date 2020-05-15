#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>     /* atoi */

/* 输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"] */

using namespace std;

void backtrack(string s, vector<int> &track, int start, vector<vector<int>> &res){
    if(track.size() == 3 && atoi(s.substr(track.back()).c_str()) < 255) {
        res.push_back(track);
        return;
    }
    for(int i = start; i < s.size() - 1; i++){
        if(find(track.begin(), track.end(), i) != track.end())
            continue;
        string temp;
        if(track.size() == 0)
            temp = s.substr(0, i);
        else
            temp = s.substr(track.back(), i - track.back()); 
        int t = atoi(temp.c_str());
        if(t > 255 || t < 1)
            continue;     
        track.push_back(i);
        backtrack(s, track, i + 1, res);
        track.pop_back();
    }
}

vector<string> restoreIpAddresses(string s){
    vector<int> track;
    vector<vector<int>> res;
    backtrack(s, track, 0, res);

    vector<string> ans;
    for(auto pos : res){
        string temp = s;
        int count = 0;
        for(auto p : pos){
            temp.insert(temp.begin() + p + count, '.');
            count++;
        }
        ans.push_back(temp);
    }
    return ans;

}

int main(){
    string s = "25525511135";
    
    vector<string> res;
    res = restoreIpAddresses(s);
    for(auto s : res)
        cout << s << endl;

    return 0;
}