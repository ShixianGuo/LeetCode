// @File   : 41_firstMissingPositive.cpp
// @Source : https://leetcode-cn.com/problems/first-missing-positive/
// @Title  : 41. 缺失的第一个正数
// @Auther : sun_ds
// @Date   : 2020/5/7

/**  题目描述：
    给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

     

    示例 1:

    输入: [1,2,0]
    输出: 3
    示例 2:

    输入: [3,4,-1,1]
    输出: 2
    示例 3:

    输入: [7,8,9,11,12]
    输出: 1
     

    提示：

    你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/first-missing-positive
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.哈希
 * 使用set存储nums中的各个数字。
 * 理性分析，nums中最多包含nums.size()个正整数。
 * 所以，最小的正整数一定是在 [1,nums.size()+1]中的一个。
 * 遍历i = [1,nums.size()],找到set中不存在的第一个i，即为最小的正整数
 *
 * 时间复杂度O(N)
 * 空间复杂度O(N)
 *
 * 2.自己构建哈希 减少空间复杂度
 *  分析上面解法，发现程序最终的结果包含在[1,nums.size()+1]中，而set中存储了nums中所有的数。
 *  显然有一些大于nums.size()+1的值是不需要存的，即只需要存储在[1,nums.size()+1]范围内的数就行了。
 *
 *  而此时有数组nums[0:nums.size()-1]
 *  将数字i = [1:nums.size()]映射到nums[i-1]位置上。
 *  此时还差nums.size()+1没有位置，没关系。若1-nums.size()的数都有了，那么结果就是nums.size()+1
 *
 *  因此遍历数组nums
 *  若nums[i] 在 范围[1:nums.size()]内，就把他放到 nums[i]-1位置，即swap(nums[nums[i]-1],nums[i]) 继续判断缓过来的新的数字
 *  若nums[i] 不在 范围[1:nums.size()]内，那么就不管他，不影响，他肯定不满足 i == nums[i] - 1;
 *
 *  最后再次遍历nums
 *  第一个不满足 i == nums[i] - 1;的 位置即为缺失的最小正整数数字i+1.
 *
 *  时间复杂度O(N)
 *  空间复杂度O(1)
 *
 *
 *
 */


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i:nums) s.insert(i);
        //前len个整数就够了，因为nums他最多也就装len个正整数
        int len = nums.size();
        for(int i=1;i<=len;i++){
            if(!s.count(i)) return i;
        }
        return len + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(i!=nums[i]-1){
                //不在范围内不考虑
                if(nums[i]<=0||nums[i]>n) break;
                //将当前nums[i]放到正确位置，并在下一次循环，判断新换过来的数字。
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            //第一个不符合规律的值就是缺失的值
            if(nums[i]-1!=i) return i+1;
        }
        return n+1;
    }
};

