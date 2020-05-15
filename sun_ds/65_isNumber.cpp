// @File   : 65_isNumber.cpp
// @Source : https://leetcode-cn.com/problems/valid-number/
// @Title  : 65. 有效数字
// @Auther : sun_ds
// @Date   : 2020/5/15

/**  题目描述：
    验证给定的字符串是否可以解释为十进制数字。

    例如:

    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true
    " -90e3   " => true
    " 1e" => false
    "e3" => false
    " 6e-1" => true
    " 99e2.5 " => false
    "53.5e93" => true
    " --6 " => false
    "-+3" => false
    "95a54e53" => false

    说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：

    数字 0-9
    指数 - "e"
    正/负号 - "+"/"-"
    小数点 - "."
    当然，在输入中，这些字符的上下文也很重要。

    更新于 2015-02-10:
    C++函数的形式已经更新了。如果你仍然看见你的函数接收 const char * 类型的参数，请点击重载按钮重置你的代码。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/valid-number
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.就硬分类
 * 1）首先过滤掉前面的空格
 * 2）只能有一个e
 * 3）e分成两部分，前后部分都只能包含1个'+'或'-'且都必须在每部分开头位置 (判断开头位置，前面为' '或前面为'e')
 * 4）e分成两部分，只有前面部分能够包含1个'.'
 * 5）e前后必须有数字
 * 6）由于首先过滤掉了最前面的空格，所以后续再遇到空格就必须一路空格到底。且空格前面必须有数字。
 *
 *
 * https://leetcode-cn.com/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/
 * 2.有限状态机
 * 构建状态转移表。
 * 行索引为当前状态，列索引为当前输入类别。
 * 遍历输入字符串，并不断的更新状态，判断最后状态是否是符合要求的状态。
 *
 *
 */

class Solution {
public:
    bool isNumber(string s) {
        int e_flag = 0, pn_flag = 0, point_flag = 0, num_flag = 0;
        int i=0;
        //前面过滤空格
        while(i<s.size()&&isspace(s[i])) i++;
        for(;i<s.size();i++){
            if(('0'<=s[i]&&s[i]<='9')){
                num_flag = 1; //有数字了
            }else if(s[i]=='e'){
                if(e_flag==0&&num_flag!=0){
                    e_flag = 1; //第1个e
                    pn_flag = 0; //e后面正负号另算
                    point_flag = 1; //e后面不能有'.'
                    num_flag = 0; //e后面必须有数字
                }
                else return false; //不能出现多于1个e
            }else if(s[i]=='+'||s[i]=='-'){
                // '+''-'只能出现在开头(所以他必须是第一个或者他前面是空格)或e后面
                // pn_flag控制只能出现一次
                if(pn_flag==1||(i>=1&&s[i-1] != ' '&&s[i-1] != 'e')) return false;
                pn_flag = 1;
            }else if(s[i]=='.'){
                if(point_flag==1) return false; //已经有‘.’了
                point_flag = 1;
            }else if(s[i]==' '){
                //空格前面必须有数字
                if(num_flag != 0){
                    while(i<s.size()&&s[i]==' ') i++;
                    //要是空格就一路空格到底
                    if(i == s.size()) return true;
                    else return false;
                }else{
                    return false;
                }
            }else{ //不合法字符
                return false;
            }
        }
        //防止最后一位为e
        if(num_flag == 1) return true;
        else return false;
    }
};


class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        int n = s.size();

        int state = 0;
        vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1}); // 合法的终止状态
        vector<vector<int> > transfer({
                                              //  空格 +/- 0-9  .   e  other
                                              {0,  1,  6,  2,  -1, -1},   //开始状态
                                              {-1, -1, 6,  2,  -1, -1},   //前面是+/-
                                              {-1, -1, 3,  -1, -1, -1},   //前面是.
                                              {8,  -1, 3,  -1, 4,  -1},   //前面是数字，且已经有过了.
                                              {-1, 7,  5,  -1, -1, -1},   //前面是e
                                              {8,  -1, 5,  -1, -1, -1},   //前面是数字，且 e 出现过
                                              {8,  -1, 6,  3,  4,  -1},   //前面是数字，且 e 没出现过
                                              {-1, -1, 5,  -1, -1, -1},   //前面是+/-，且 e 出现过
                                              {8,  -1, -1, -1, -1, -1},   //处理完成，处理空格状态
                                      });

        for(int i = 0; i < n; ++i)
        {
            state = transfer[state][_make(s[i])];
            if(state < 0) return false;
        }
        return finals[state];
    }

private:
    int _make(const char& c)
    {
        switch(c)
        {
            case ' ': return 0;
            case '+': return 1;
            case '-': return 1;
            case '.': return 3;
            case 'e': return 4;
            default: return _number(c);
        }
    }

    int _number(const char& c)
    {
        if(c >= '0' && c <= '9')
            return 2;
        else
            return 5;
    }
};

