// @File   : 1106_parseBoolExpr.cpp
// @Source : https://leetcode-cn.com/problems/parsing-a-boolean-expression/
// @Title  : 1106. 解析布尔表达式
// @Auther : sun_ds
// @Date   : 2020/5/3

/**  题目描述：
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

/**
 *
 * 使用栈
 * 使用栈存储表达式
 *  1.遇到','跳过
 *  2.遇到')',开始处理
 *  3.其他符号，入栈
 *
 *  遇到')'，符号依次出栈，直到遇到'('.则此时'('为')'前的第一个'(',因此中间肯定为'f'或't'
 *  使用变量 f 和 t 统计括号中是否出现过'f'或't'。
 *  将'('出栈。
 *  此时栈顶必为符号'&','|','!'.
 *  将符号出栈，并判断当前符号类型，根据变量f和t，计算括号中的值，并将计算所得的值重新入栈，供后面计算使用。
 *
 *  最后，遍历并结合所以表达式，栈中只剩下最终结果值。
 *  判断 s.top() == 't' 即为最终结果。
 *
 *
 */

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        for(auto c:expression){
            switch(c){
                case ',':
                    break;
                case '!':
                    s.push('!');
                    break;
                case '|':
                    s.push('|');
                    break;
                case '&':
                    s.push('&');
                    break;
                case 't':
                    s.push('t');
                    break;
                case 'f':
                    s.push('f');
                    break;
                case '(':
                    s.push('(');
                    break;
                case ')':{
                    bool f = false, t = false; //记录是否有false和true
                    for(;s.top()!='(';s.pop()){
                        if(s.top()=='f') f = true;
                        else t = true;
                    }
                    s.pop();
                    char op = s.top();
                    s.pop();
                    switch(op){
                        case '&':
                            if(!f)//一个false都没有，那么&的结果是true
                                s.push('t');
                            else
                                s.push('f');
                            break;
                        case '|':
                            if(!t)//一个true都没有，那么|的结果才false
                                s.push('f');
                            else
                                s.push('t');
                            break;
                        case '!':
                            if(!t)//没有t，他就是f，!后就是t
                                s.push('t');
                            else //没有f，他就是t，!后就是f
                                s.push('f');
                            break;
                        default : ;
                    }
                    break;
                }
                default : ;
            }
        }
        return s.top() == 't';
    }
};


