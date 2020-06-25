#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool connect(const string& word1,const string &word2)//判断两个单词是否仅一个字母不同
{
    int dif=0; //不同的字母数量
    for(int i=0;i<word1.length();i++)
    {
        if(word1[i]!=word2[i]) 
            dif++;
        if(dif>1)
            return false;
    }
    return dif==1;
} 

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_map<string, vector<string>> m;
    wordList.push_back(beginWord);
    for(int i = 0; i < wordList.size(); i++){
        for(int j = 0; j < wordList.size(); j++){
            if(connect(wordList[i], wordList[j]) == true && (i != j)){
                m[wordList[i]].push_back(wordList[j]);
                m[wordList[j]].push_back(wordList[i]);
            }
        }
    }
    unordered_set<string> isVisited;
    queue<string> q;
    q.push(beginWord);

    int res = 1;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            string temp = q.front();
            q.pop();
            isVisited.insert(temp);
            for(auto word : m[temp]){
                if(isVisited.count(word) != 0)
                    continue;
                q.push(word);
                isVisited.insert(word);
                if(word ==  endWord)
                    return res + 1;
            } 
        }
        res++;
    }
    return 0;
}

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << ladderLength(beginWord, endWord, wordList) << endl;

}