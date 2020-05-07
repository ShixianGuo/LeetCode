// @File   : 88_merge.cpp
// @Source : https://leetcode-cn.com/problems/merge-sorted-array/
// @Title  : 88. 合并两个有序数组
// @Auther : sun_ds
// @Date   : 2020/5/1

/**  题目描述：
    给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

     

    说明:

    初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
     

    示例:

    输入:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    输出: [1,2,2,3,5,6]


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/merge-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 1.双指针
 * 计算好合并后长度。
 * 从后往前填充nums1.
 * 不使用额外空间。
 *
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n;
        m--;
        n--;
        for(int i=k-1;i>=0;i--){
            if(n<0){
                nums1[i] = nums1[m--];
            }else if(m<0){
                nums1[i] = nums2[n--];
            }else{
                if(nums1[m]>nums2[n]){
                    nums1[i] = nums1[m--];
                }else{
                    nums1[i] = nums2[n--];
                }
            }
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        while(m>0&&n>0){
            nums1[k--] = nums1[m-1] > nums2[n-1] ? nums1[--m] : nums2[--n];
        }
        if(n!=0){
            for(int i=0;i<n;i++){
                nums1[i] = nums2[i];
            }
        }
    }
};