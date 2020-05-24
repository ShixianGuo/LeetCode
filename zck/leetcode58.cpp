//最后一个单词的长度
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLastWord(string s){
    reverse(s.begin(), s.end());
    int i;
    for(i = 0; i < s.size(); i++){
        if(s[i] != ' ')
            break;
    }
    s = s.substr(i);
    int j;
    for(j = 0; j < s.size(); j++){
        if(s[j] == ' ')
            break;
    }
    return j;
}

int main(){
    cout << lengthOfLastWord("     Hello World      ") << endl;

    return 0;
}