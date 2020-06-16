/*
输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
*/

//回溯法,超时
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s){
    bool result = true;
    for(int i = 0; i < s.size() / 2; i++){
        if(s[i] != s[s.size() - i - 1])
            result = false;
    }
    return result;
}

void backtrack(string s, int start, vector<string>& track, vector<vector<string>>& res){
    if(start >= s.size()){
        res.push_back(track);
        return;
    }
    for(int i = start; i < s.size(); i++){
        string temp = s.substr(start, i - start + 1);
        if(!isPalindrome(temp))
            continue;
        track.push_back(temp);
        backtrack(s, i + 1, track, res);
        track.pop_back();
    }
}

int minCut(string s){
    vector<string> track;
    vector<vector<string>> res;
    backtrack(s, 0, track, res);
    int min_cut = INT32_MAX;
    for(auto strs : res)
        min_cut = min(min_cut, int(strs.size()) - 1);

    return min_cut;
}

int main(){
    string s = "abcba";
    cout << minCut(s) << endl;

    return 0;
}