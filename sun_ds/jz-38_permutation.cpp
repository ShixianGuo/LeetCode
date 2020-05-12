// @File   : jz-38_permutation.cpp
// @Source : https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
// @Title  : 面试题38. 字符串的排列
// @Auther : sun_ds
// @Date   : 2020/5/9

/**  题目描述：
    输入一个字符串，打印出该字符串中字符的所有排列。

     

    你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

     

    示例:

    输入：s = "abc"
    输出：["abc","acb","bac","bca","cab","cba"]
     

    限制：

    1 <= s 的长度 <= 8

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.回溯法
 *  后面位置与当前位置交换。
 *  注意去重
 *  1.1set去重
 *  1.2判断 若当前元素与本轮前面元素是否有重复的。如果有重复的，那么将当前元素交换到index位置和前面是一样的
 *
 *
 *
 *
 */

class Solution {
public:
    vector<string> res;
    bool judge(string s,int start,int end){
        while(start<end){
            if(s[start++]==s[end]) return true;
        }
        return false;
    }
    void func(string s,int index){
        if(index==s.size()){
            res.push_back(s);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(judge(s,index,i)) continue;  //判断，若当前元素与本轮前面元素是否有重复的。如果有重复的，那么将当前元素交换到index位置和前面是一样的
            swap(s[index],s[i]); //修改
            func(s,index+1);
            swap(s[index],s[i]); //恢复
        }
    }
    vector<string> permutation(string s) {
        func(s,0);
        return res;
    }
};

class Solution {
public:
    unordered_set<string> res;
    void func(string s,int index){
        if(index==s.size()){
            res.insert(s);
            return;
        }
        for(int i=index;i<s.size();i++){
            swap(s[index],s[i]);
            func(s,index+1);
            swap(s[index],s[i]);
        }
    }
    vector<string> permutation(string s) {
        func(s,0);
        return vector<string>(res.begin(),res.end());
    }
};
