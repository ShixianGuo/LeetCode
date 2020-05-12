#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk1;//保存逻辑运算符
        stack<char> stk2;//保存“数”
        //从左到右，而且遍历完最后一个')'括号时一定只剩stk2中一个元素
        for (int i = 0; i < expression.size(); i++) {
            //是操作符就入stk1
            if (expression[i] == '|' || expression[i] == '&' || expression[i] == '!')
                stk1.push(expression[i]);
            //是')'就知道要进行一次运算了
            else if (expression[i] == ')') {
                int t = 0;//记录f和t出现的次数
                int f = 0;
                while (stk2.top() != '(') {//这对括号里的就是要操作的“数”
                    if (stk2.top() == 't')
                        t++;
                    if (stk2.top() == 'f')
                        f++;
                    stk2.pop();
                }
                stk2.pop();
                char x = stk1.top();//弹出逻辑运算符
                stk1.pop();
                //接下来就是运算，并将结果压栈
                if (x == '!') {
                    if (t == 1)
                        stk2.push('f');
                    else
                        stk2.push('t');
                }
                else if (x == '|') {
                    if (t != 0)
                        stk2.push('t');
                    else
                        stk2.push('f');
                }
                else if (x == '&') {
                    if (f != 0)
                        stk2.push('f');
                    else
                        stk2.push('t');
                }
            }
            else
                stk2.push(expression[i]);
        }
        if (stk2.top() == 't') return true;//在表达式没有错误的情况，最后一定只会剩一个
        else return false;

    }
};
