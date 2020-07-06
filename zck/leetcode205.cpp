#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.size() != t.size())
        return false;
    unordered_map<char, char> m;
    for(int i = 0; i < s.size(); i++){
        m[s[i]] = t[i];   
    }
    for(int i = 0; i < s.size(); i++){
        if(m[s[i]] != t[i])
            return false;
    }
    return true;
}


int main(){
    cout << isIsomorphic("egg", "add") << endl;
    cout << isIsomorphic("foo", "bar") << endl;
    cout << isIsomorphic("aba", "baa") << endl;

    return 0;
}