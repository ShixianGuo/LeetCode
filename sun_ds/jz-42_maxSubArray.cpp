// @File   : jz-42_maxSubArray.cpp
// @Source : https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
// @Title  : 面试题42. 连续子数组的最大和
// @Auther : sun_ds
// @Date   : 2020/5/9

/**  题目描述：
    输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

    要求时间复杂度为O(n)。

     

    示例1:

    输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出: 6
    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
     

    提示：

    1 <= arr.length <= 10^5
    -100 <= arr[i] <= 100
    注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.dp
 *
 * dp[i]表示以nums[i]结尾的连续子数组的最大和。
 * 这样定义的原因是为了，保证dp[i]递推到dp[i+1]的正确性；如果不包含nums[i]，递推时则不满足题目的连续子数组要求。
 * 转移方程：
 * 若dp[i-1]>0 dp[i] = dp[i-1]+nums[i]
 * 若dp[i-1]<=0 dp[i] = nums[i] 前面的子数组产生负贡献，还不如只要本身
 * 因此有 dp[i] = max(nums[i],dp[i-1]+nums[i]);
 * 最终的结果是dp中最大的值。
 *
 * 时间复杂度O(N)
 * 空间复杂度O(N)
 * 使用滚动思想，降低一维，空间复杂度O(1)
 *
 * 2.分治法(线段树)
 * 对于每一个区间[l,r]维护四个值。
 *   1)lSum:以l为左端点的最大子段和
 *   2)rSum:以r为右端点的最大子段和
 *   3)mSum:区间内的最大子段和
 *   4)iSum:整个区间和
 * 二分的划分区间。当区间内只有一个值时，上面四个取值都为该值，返回。
 * 二分递归返回后，需要合并。
 *   左右两部分区间合并[l,mid]和[mid+1,r]
 *   1)合并后区间和 = 左区间和 + 右区间和;
 *   2)合并后以l为左端点的最大子段和 = max(左区间左端点的最大子段和，左区间和+右区间的左端点最大子段和);
 *   3)合并后以r为右端点的最大子段和 = max(右区间右端点的最大子段和，右区间和+左区间的右端点最大子段和);
 *   4)合并后区间内最大字段和 = max(左区间的最大子段和，右区间的最大子段和，左区间的右端点最大子段和+右区间的左端点最大子段和);
 *
 * 时间复杂度:O(sum(2^i-1)) i = [1,log(n)]  故渐进时间复杂度为O(N)
 * 空间复杂度:O(logN) 递归的栈空间
 *
 * 优势：可以求任意区间内的最大子段和。
 *
 *
 *
 *
 */

//dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            res = max(res,dp[i]);
        }
        return res;
    }
};

//dp+滚动思想
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = 0, res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            dp = max(nums[i],dp+nums[i]);
            res = max(res,dp);
        }
        return res;
    }
};

//线段树思想
class Solution {
public:
    struct Status {
        //当前区间[l,r]
        //lSum:以l为左端点的最大子段和
        //rSum:以r为右端点的最大子段和
        //mSum:区间内的最大子段和
        //iSum:整个区间和
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        //左右两部分区间合并[l,mid]和[mid+1,r]
        //合并后区间和 = 左区间和 + 右区间和;
        int iSum = l.iSum + r.iSum;
        //合并后以l为左端点的最大子段和 = max(左区间左端点的最大子段和，左区间和+右区间的左端点最大子段和);
        int lSum = max(l.lSum, l.iSum + r.lSum);
        //合并后以r为右端点的最大子段和 = max(右区间右端点的最大子段和，右区间和+左区间的右端点最大子段和);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        //合并后区间内最大字段和 = max(左区间的最大子段和，右区间的最大子段和，左区间的右端点最大子段和+右区间的左端点最大子段和);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        //区间内只有一个元素，四个值都是他本身
        if (l == r) return (Status) {a[l], a[l], a[l], a[l]};
        //分治
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        //合并
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        //返回区间的最大子段和
        return get(nums, 0, nums.size() - 1).mSum;
    }
};
