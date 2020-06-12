/*
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens){
    stack<string> st;
    for(auto token : tokens){
        if(token == "+"){
            int num1 = stoi(st.top());
            st.pop();
            int num2 = stoi(st.top());
            st.pop();
            int tmp = num1 + num2;
            st.push(to_string(tmp));    
        }
        else if(token == "-"){
            int num1 = stoi(st.top());
            st.pop();
            int num2 = stoi(st.top());
            st.pop();
            int tmp = num2 - num1;
            st.push(to_string(tmp));    
        }
        else if(token == "*"){
            int num1 = stoi(st.top());
            st.pop();
            int num2 = stoi(st.top());
            st.pop();
            int tmp = num1 * num2;
            st.push(to_string(tmp));    
        }
        else if(token == "/"){
            int num1 = stoi(st.top());
            st.pop();
            int num2 = stoi(st.top());
            st.pop();
            int tmp = num2 /  num1;
            st.push(to_string(tmp));    
        }
        else{
            st.push(token);
        }
    }
    return stoi(st.top());
}

int main(){
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens) << endl;

    return 0;
}

