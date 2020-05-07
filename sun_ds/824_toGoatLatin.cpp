// @File   : 824_toGoatLatin.cpp
// @Source : https://leetcode-cn.com/problems/goat-latin/
// @Title  : 824. 山羊拉丁文
// @Auther : sun_ds
// @Date   : 2020/5/5

/**  题目描述：
    给定一个由空格分割单词的句子 S。每个单词只包含大写或小写字母。

    我们要将句子转换为 “Goat Latin”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。

    山羊拉丁文的规则如下：

    如果单词以元音开头（a, e, i, o, u），在单词后添加"ma"。
    例如，单词"apple"变为"applema"。

    如果单词以辅音字母开头（即非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
    例如，单词"goat"变为"oatgma"。

    根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从1开始。
    例如，在第一个单词后添加"a"，在第二个单词后添加"aa"，以此类推。
    返回将 S 转换为山羊拉丁文后的句子。

    示例 1:

    输入: "I speak Goat Latin"
    输出: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
    示例 2:

    输入: "The quick brown fox jumped over the lazy dog"
    输出: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
    说明:

    S 中仅包含大小写字母和空格。单词间有且仅有一个空格。
    1 <= S.length <= 150。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/goat-latin
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 划分单词，判断是否是元音(如果是不是元音将第一个字符移至末尾)，添加"ma"和索引个数的"a"
 *
 */


class Solution {
public:
    string toGoatLatin(string S) {
        //存储元音 要包括大小写
        unordered_set<char> vowel = {'a','e','i','o','u','A','E','I','O','U'};
        //分出单词
        stringstream ss(S);
        vector<string> word;
        string temp;
        while(ss>>temp){
            word.push_back(temp);
        }
        //遍历处理各个单词
        string res;
        for(int i=0;i<word.size();i++){
            string tt;
            if(vowel.count(word[i][0])){
                //是元音
                tt = word[i] + "ma";
            }else{
                //不是元音
                tt = word[i].substr(1) + word[i][0] + "ma";
            }
            //添加索引个数的'a'
            tt += string(i+1,'a');
            res += tt + ' ';
        }
        //去掉最后一个空格
        return res.substr(0,res.size()-1);
    }
};

//合并步骤
class Solution {
public:
    string toGoatLatin(string S) {
        //存储元音 要包括大小写
        unordered_set<char> vowel = {'a','e','i','o','u','A','E','I','O','U'};
        //分出单词 并 处理
        stringstream ss(S);
        string temp;
        string res;
        int count=0;
        while(ss>>temp){
            string tt;
            if(vowel.count(temp[0])){
                //是元音
                tt = temp + "ma";
            }else{
                //不是元音
                tt = temp.substr(1) + temp[0] + "ma";
            }
            //添加索引个数的'a'
            tt += string(++count,'a');
            res += tt + ' ';
        }
        //去掉最后一个空格
        return res.substr(0,res.size()-1);
    }
};


