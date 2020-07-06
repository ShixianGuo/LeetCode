/*s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
*/


#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ']'){
            string temp = "";
            while(st.top() != '['){
                temp = st.top() + temp;
                st.pop();
            }
             st.pop();
            
            string times = "";
            while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                times = st.top() + times;
                st.pop();
            }          

            for(int j = 0; j < stoi(times); j++){
                for(auto c : temp){
                    st.push(c);
                }
            }
        }
        else{
            st.push(s[i]);
        }
    }
    string res = "";
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    return res;
}

int main(){

    cout << decodeString("2[abc]3[cd]ef") << endl;

    return 0;
}