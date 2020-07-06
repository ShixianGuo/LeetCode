/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
*/

#include <iostream>
#include <vector>
#include <string> 
#include <unordered_set>

using namespace std;

void backtrack(string s, int start, vector<string> &track, vector<vector<string>>& res, unordered_set<string> dict){
    if(start >= s.size()){
        res.push_back(track);
        return;
    }
    for(int i = start; i < s.size(); i++){
        string temp = s.substr(start, i - start + 1);
        if(dict.count(temp) == 0)
            continue;
        track.push_back(temp);
        backtrack(s, i + 1, track, res, dict);
        track.pop_back();
    }
}

bool wordBreak(string s, vector<string>& wordDict) {
    vector<string> track;
    vector<vector<string>> res;
    unordered_set<string> dict;
    for(auto word : wordDict)
        dict.insert(word);

    backtrack(s, 0, track, res, dict);
    if(res.size() == 0)
        return false;
    return true;
}

int main(){
    string s = "catsandog"; 
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

    cout << wordBreak(s, wordDict) << endl;

    return 0;
}


