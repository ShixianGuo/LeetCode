// @File   : jz-39_majorityElement.cpp
// @Source : https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
// @Title  : 面试题39. 数组中出现次数超过一半的数字
// @Auther : sun_ds
// @Date   : 2020/5/16

/**  题目描述：
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

     

    你可以假设数组是非空的，并且给定的数组总是存在多数元素。

     

    示例 1:

    输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
    输出: 2
     

    限制：

    1 <= 数组长度 <= 50000

     

    注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 *
 * 1.投票法
 *  第一个当做众数，作为候选，后面与候选相同计数count加1否则减1.
 *  如count为0，当前值当做众数，作为候选。输出候选即为众数
 *
 *
 *
 */



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int count = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(count==0) res = nums[i];
            count += nums[i] == res ? 1:-1;
        }
        return res;
    }
};


