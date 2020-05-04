class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        // 每次能接到的水是 max(leftmax, rightmax) - height[i] 这样暴力就能做出来了

        // 双指针做法
        // 双指针从左右两边向中间计算，lefMax 存储左边到 left 的最大值，rightMax 存储右边到 right 的最大值，如果 lefMax <= rightMax 那么因为短板效应，可以计算左边，同理如右
        int left = 0, right = height.size() - 1, lefMax = height[left], rightMax = height[right], ans = 0;
        while(left < right) {
            if(lefMax <= rightMax) {
                ans += lefMax - height[left];
                left++;
                lefMax = max(lefMax, height[left]);
            }  else {
                ans += rightMax - height[right];
                right--;
                rightMax = max(rightMax, height[right]);
            }
        }
        return ans;
    }
};
