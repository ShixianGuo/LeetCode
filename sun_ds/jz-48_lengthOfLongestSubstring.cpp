// @File   : jz-48_lengthOfLongestSubstring.cpp
// @Source : https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
// @Title  : 面试题48. 最长不含重复字符的子字符串
// @Auther : sun_ds
// @Date   : 2020/5/4

/**  题目描述：
    请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

     

    示例 1:

    输入: "abcabcbb"
    输出: 3
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
    示例 2:

    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
    示例 3:

    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
     

    提示：

    s.length <= 40000
    注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/



    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 滑动窗口
 * 循环后移尾端并统计长度
 * 如果尾端字符已经存在了，则以前面存在字符的后一位和当前起始index比较，取大的。
 * 继续计算窗口长度
 *
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1) return n;
        vector<int> count(256,-1);
        int start = 0;
        int res = 0 ;
        for(int i=0;i<n;i++){
            if(count[s[i]]!=-1){
                start = max(start,count[s[i]]+1);
            }
            res = max(res,i - start + 1);
            count[s[i]] = i;
        }
        return res;
    }
};




