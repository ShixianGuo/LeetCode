/*
 给你一个以字符串形式表述的 布尔表达式（boolean） expression，返回该式的运算结果。

有效的表达式需遵循以下约定：

"t"，运算结果为 True
"f"，运算结果为 False
"!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
"&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
"|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/parsing-a-boolean-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <iostream>
using namespace std;
/*
expr-> factor| !(expr) | &(expr exprmore) | ^(expr exprmore) 
exprmore -> ,expr exprmore | ε
factor -> f | t

*/

class Solution {
    std::string data_;
    size_t idx_;
    char peek(){
        return data_[idx_];
    }
    char match(char c,char expect){
        if(c==expect){
            idx_++;
            return expect;
        }
        throw std::runtime_error("parse error!");
    }

    bool expr(){
        if(peek()=='f'||peek()=='t'){
            return factor();
        }else if(peek()=='!'){
            match(peek(),'!');
            match(peek(),'(');
            bool e=expr();
            match(peek(),')');
            return !e;
            
        }else if(peek()=='&'){
            match(peek(),'&');
            match(peek(),'(');
            bool e=expr(),em=exprmore('&');
            match(peek(),')');
            return e&&em;
        }else if(peek()=='|'){
            match(peek(),'|');
            match(peek(),'(');
            bool e=expr(),em=exprmore('|');
            match(peek(),')');
            return e||em;
            
        }
        return true;
        
    }
    bool exprmore(char c){
        if(idx_<data_.size() &&peek()==','){
            match(peek(),',');
            if(c=='|'){
                bool e=expr(),em=exprmore(c);
                return e||em;
            }else{
                bool e=expr(),em=exprmore(c);
                return e&&em;
            }
            
        }else{
            if(c=='|'){
                return false;
            }else{
                return true;
            }
        }
    }
    bool factor(){
        if(peek()=='f'){
            match(peek(),'f');
            return false;
        }else{
            match(peek(),'t');
            return true;
        }
    }


public:

    bool parseBoolExpr(string expression) {
        data_=expression;
        idx_=0;
        return expr();
    }
};


int main(){
    Solution s;
    //&(!(&(f)),&(t),|(f,f,t)),&(t),&(t,t,f)
    cout<<s.parseBoolExpr("!(f)")<<endl;;

}