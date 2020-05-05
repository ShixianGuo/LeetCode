#pragma once
#include"entity.h"

using namespace std;
/*
给你一个以字符串形式表述的 布尔表达式（boolean） expression，返回该式的运算结果。

有效的表达式需遵循以下约定：

"t"，运算结果为 True
"f"，运算结果为 False
"!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
"&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
"|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）
 

示例 1：

输入：expression = "!(f)"
输出：true
示例 2：

输入：expression = "|(f,t)"
输出：true
示例 3：

输入：expression = "&(t,f)"
输出：false
示例 4：

输入：expression = "|(&(t,f,t),!(t))"
输出：false
 

提示：

1 <= expression.length <= 20000
expression[i] 由 {'(', ')', '&', '|', '!', 't', 'f', ','} 中的字符组成。
expression 是以上述形式给出的有效表达式，表示一个布尔值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/parsing-a-boolean-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
	//思路1：能不能使用递归，不行，多重套嵌的话很难找到分割逗号
	//思路2：表达式运算参照后缀表达式的计算方法
	bool parseBoolExpr(string expression) {
		stack<char> op;
		stack<char> expr;

		for (char x : expression) {
			if (x == '|'||x == '&'||x == '!') {
				op.push(x);
			}
			else if (x == ')') {
				//取出expr
				int t = 0, f = 0;//统计个数
				while (expr.top() != '(') {
					if (expr.top() == 't') ++t;
					else if (expr.top() == 'f') ++f;
					//如果是逗号就直接忽略
					expr.pop();
				}
				expr.pop();//pop掉'('

				//取出op开始计算
				if (op.top() == '!') {
					if (t == 1) expr.push('f');
					else expr.push('t');
				}
				else if (op.top() == '&') {
					//必须没有false
					if (f == 0) expr.push('t');
					else expr.push('f');
				}
				else if (op.top() == '|') {
					if (t == 0) expr.push('f');
					else expr.push('t');
				}
				op.pop();//删去一个
			}
			else {
				//如果x='(',x=','
				expr.push(x);
			}
		}
		//最后只剩下一个expr
		if (expr.top() == 't') return true;
		return false;
	}
};