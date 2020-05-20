// @File   : 557_reverseWords.cpp
// @Source : https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
// @Title  : 557. 反转字符串中的单词 III
// @Auther : sun_ds
// @Date   : 2020/5/18

/**  题目描述：
    给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

    示例 1:

    输入: "Let's take LeetCode contest"
    输出: "s'teL ekat edoCteeL tsetnoc" 
    注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.双指针
 * 记录单词的起始和结束位置
 * 使用swap交换
 *
 *
 */

class Solution {
public:
    string reverseWords(string s) {
        int l = 0 , r = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){ //空格就跳过
                r = i-1;
                //前后向中间靠拢 交换
                while(l<r){
                    swap(s[l++],s[r--]);
                }
                l = i+1;
            }
        }
        //反转最后一个单词
        r = s.size()-1;
        while(l<r){
            swap(s[l++],s[r--]);
        }
        return s;
    }
};