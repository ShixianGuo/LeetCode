// @File   : jz-51_reversePairs.cpp
// @Source : https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
// @Title  : 面试题51. 数组中的逆序对
// @Auther : sun_ds
// @Date   : 2020/5/9

/**  题目描述：
    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

     

    示例 1:

    输入: [7,5,6,4]
    输出: 5
     

    限制：

    0 <= 数组长度 <= 50000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/bao-li-jie-fa-fen-zhi-si-xiang-shu-zhuang-shu-zu-b/
 * 1.借助归并排序
 *
 * 逆序对来源于 3 个部分：
 *  左边区间的逆序对
 *  右边区间的逆序对
 *  横跨两个区间的逆序对
 *
 * 后有序数组中元素出列的时候，计算逆序个数；
 *
 *
 * 在归并排序的合并阶段统计逆序个数。
 * i指向前部分将要合并的值，j指向后部分将要合并的值，mid指向前部分的末尾。
 * 当j要合并的时候。[i,mid]之间的元素肯定是大于j的，此时产生逆序。
 * 逆序个数 加上 该区间长度 mid-i+1
 *
 *
 */

class Solution {
public:
    int merge_count(vector<int>& nums,int l,int mid,int r,vector<int>& temp){
        for(int c=l;c<=r;c++) temp[c] = nums[c];
        int count=0;
        int i=l;
        int j=mid+1;
        for(int k=l;k<=r;k++){
            if(i>mid){
                nums[k] = temp[j];
                j++;
            }else if(j>r){
                nums[k] = temp[i];
                i++;
            }else if(temp[i]<=temp[j]){
                nums[k] = temp[i];
                i++;
            }else{
                nums[k] = temp[j];
                j++;
                count += (mid - i + 1);
            }
        }
        return count;
    }
    int count_reverse(vector<int>& nums,int l,int r,vector<int>& temp){
        if(l==r) return 0;
        int mid = l + ((r - l)>>1);
        int l1 = count_reverse(nums,l,mid,temp);
        int r1 = count_reverse(nums,mid+1,r,temp);
        int res = l1 + r1;
        if(nums[mid]<=nums[mid+1]){  //剪枝 已经有序了
            return res;
        }
        int c = merge_count(nums,l,mid,r,temp);
        res += c;
        return res;

    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        vector<int> temp(n);
        return count_reverse(nums,0,n-1,temp);
    }
};


