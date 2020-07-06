#include <iostream>
#include <vector>
#include <string>

using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        words.push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        for(auto w : words){
            if(isMatch(w, word))
                return true;
        }
        return false;
    }
    bool isMatch(string word1, string word2){
        if(word1.size() != word2.size())
            return false;
        for(int i = 0; i < word1.size(); i++){
            if(word2[i] == '.')
                continue;
            if(word1[i] != word2[i])
                return false;
        }
        return true;
    }
private:
    vector<string> words;
};

int main(){

    WordDictionary* obj = new WordDictionary();

    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");

    cout << obj->search("pad") << endl;
    cout << obj->search("bad") << endl;
    cout << obj->search(".ad") << endl;
    cout << obj->search("b..") << endl;

    return 0;
}
