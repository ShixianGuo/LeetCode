#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
/*
vector<string> findRepeatedDnaSequences(string s){
    if(s == "" || s.size() < 10)
        return {};
    unordered_map<string, int> m;
    for(int i = 0; i < s.size() - 10 + 1; i++){
        string temp = s.substr(i, 10);
        m[temp] += 1;
    }
    vector<string> res;
    for(auto ptr = m.begin(); ptr != m.end(); ptr++){
        if(ptr->second > 1){
            res.push_back(ptr->first);
        }
    }
    return res;
}
*/

vector<string> findRepeatedDnaSequences(string s){
    if(s == "" || s.size() < 10)
        return {};

    vector<string> res;
    unordered_set<string> st;
    for(int i = 0; i < s.size() - 10 + 1; i++){
        string temp = s.substr(i, 10);
        if(st.count(temp) == 0){
            st.insert(temp);
        }
        else{
            res.push_back(temp);
        }
    }
    auto last = unique(res.begin(), res.end());
    res.erase(last, res.end());
    
    return res;
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    cout << findRepeatedDnaSequences(s)[0] << endl;
    cout << findRepeatedDnaSequences(s)[1] << endl;

    return 0;
}

