/*
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict){
    queue<string> q;
    q.push(s);
    unordered_set<string> dict;
    for(auto word : wordDict){
        dict.insert(word);
    }
    while(!q.empty()){
        string temp = q.front();
        q.pop();
        if(dict.count(temp) != 0)
            return true;
        for(int i = 0; i < s.size(); i++){
            string w = temp.substr(0, i);
            if(dict.count(w) != 0){
                q.push(temp.substr(i));
            }
        }
    }   
    return false;
}

int main(){
    string s = "leeetcode";
    vector<string> wordDict = {"leet", "code"};

    cout << wordBreak(s, wordDict) << endl;

    return 0;
}
