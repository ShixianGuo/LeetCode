/*
*输入： pattern = "abba", value = "dogcatcatdog"
*输出： true
*/

//不能过所有case，当patter或者value为空字符串的时候，处理不好
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> helper(string pattern, string value, int len_a, int len_b){
    vector<string> res;
    string a, b;
    int index = 0;
    for(int i = 0; i < pattern.size(); i++){
        if(pattern[i] == 'a'){
            a = value.substr(index, len_a);
            index += len_a;
        }
        else{
            b = value.substr(index, len_b);
            index += len_b;
        }
    }
    return {a, b};
}

bool patternMatching(string pattern, string value){
    if(pattern == "" && value == "")
        return true;
    if(pattern == "" && value != "")
        return true;
    if(pattern != "" && value == "")
        return false;
    string a, b;
    int len_a, len_b;
    int count_a = 0, count_b = 0;
    for(auto c : pattern){
        if(c == 'a')
            count_a++;
        else
            count_b++;
    }
    if(count_a == 0){
        len_b = value.size() / pattern.size();
        b = value.substr(0, len_b);
        string s = "";
        for(int i = 0; i < pattern.size(); i++){
            s += b;
        }
        if(s == value)
            return true;
        return false;
    }
    if(count_b == 0){
        len_a = value.size() / pattern.size();
        a = value.substr(0, len_a);
        string s = "";
        for(int i = 0; i < pattern.size(); i++){
            s += a;
        }
        if(s == value)
            return true;
        return false;
    }

    int n = value.size();
    for(len_a = 1; len_a < n - 1; len_a++){
        if((n - len_a * count_a) % count_b == 0){
            len_b = (n - len_a * count_a) / count_b;
            vector<string> temp = helper(pattern, value, len_a, len_b);
            a = temp[0];
            b = temp[1];
            string s;
            for(auto c : pattern){
                if(c == 'a')
                    s += a;
                else
                    s += b;
            }
            if(s == value)
                return true;
        }
    }
    return false;
}

int main(){
    string pattern = "abba";
    string value = "dogdogdogdog";
    cout << patternMatching(pattern, value) << endl;

    return 0;
}