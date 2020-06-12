/*
*输入: "the sky is blue"
*输出: "blue is sky the"
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string s){

    int i = 0;
    while(s[i] == ' '){
        i++;
    }

    int j = s.size() - 1;
    while(s[j] == ' ')
        j--;
    
    s = s.substr(i, j - i + 1);

    reverse(s.begin(), s.end());

    string res = "";

    string word = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            reverse(word.begin(), word.end());
            res += word;
            res += ' ';
            word = "";
        }
        else{
            word += s[i];
        }
    }
    reverse(word.begin(), word.end());
    res += word;

    return res;
}

int main(){
    string s =  "  hello world!  ";
    cout << reverseWords(s) << endl;

    return 0;
}