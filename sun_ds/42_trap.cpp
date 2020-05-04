// @File   : 42_trap.cpp
// @Source : https://leetcode-cn.com/problems/trapping-rain-water/
// @Title  : 42. 接雨水
// @Auther : sun_ds
// @Date   : 2020/5/4

/**  题目描述：
    给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

    上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

    示例:

    输入: [0,1,0,2,1,0,1,3,2,1,2,1]
    输出: 6

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/trapping-rain-water
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 接雨水
 *
 * 1.按列求
 * 遍历每一列，理性分析，当前列的墙上是否有水，和他左边最大值和右边最大值有关。木桶效应。
 * 当前列上水的高度应该是min(左边最大值,右边最大值),当然前提是min(左边最大值,右边最大值)大于当前高度。
 * 遍历每个位置，并分别找出左右最大值后在计算。
 *
 * 算法复杂度O(N^2)
 *
 *
 * 2.DP
 * 提前存储各位置的左右最大的值。
 * 然后再比较当前高度与min(左右最大值)之间的关系，求当前列存的雨水。
 *
 * 算法复杂度O(N)
 *
 * 3.双指针
 *  双指针法就是将上边的一个下标 i，变为两个下标 left，right，分别位于输入数组的两端。向中间移动时，边移动边计算。
 *  除此之外，我们使用 maxleft 作为 0...left 的最大值，maxright 作为 right...结尾 的最大值。
 *  left和right向中间收缩
 *  收缩规则是，
 *  maxleft < maxright l++
 *  maxleft >= maxright r--
 *  每次先计算列上水量，然后就收缩。
 *
 *  小的向里收缩，则此时小的值(maxleft或者maxright) - height必定是水量高度。因为另一侧有比自己更大的值能够当边界。
 *  类似 11. 盛最多水的容器 双指针思想
 *
 *
 *
 * 4.单调栈
 * 构造单调递减栈。如果当前高度比栈顶低就入栈，如果当前高度比栈顶高，就将栈中元素出栈，则其中定有凹槽，统计盛水量。
 * 输入的值为栈顶右边第一个比自己大的值，栈顶前面一个元素为栈顶左边第一个比自己大的值，形成了凹槽，统计水量。
 * 统计完水量之后，栈顶就被出栈了，此时栈中只有栈顶左端和右端比自己大的值，栈顶处相当于被填平了。
 * 复杂度O(N)
 *
 *
 *
 *
 *
 */





//按列求
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        //最两端的列不用考虑，因为一定不会有水。所以下标从 1 到 length - 2
        for (int i = 1; i < height.size() - 1; i++) {
            int max_left = 0;
            //找出左边最高
            for (int j = i - 1; j >= 0; j--) {
                if (height[j] > max_left) {
                    max_left = height[j];
                }
            }
            int max_right = 0;
            //找出右边最高
            for (int j = i + 1; j < height.length; j++) {
                if (height[j] > max_right) {
                    max_right = height[j];
                }
            }
            //找出两端较小的
            int min = min(max_left, max_right);
            //只有较小的一段大于当前列的高度才会有水，其他情况不会有水
            if (min > height[i]) {
                sum = sum + (min - height[i]);
            }
        }
        return sum;
    }
};

//dp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        int sum = 0;
        vector<int> max_left(n,0);
        vector<int> max_right(n,0);

        for (int i = 1; i < n - 1; i++) {
            max_left[i] = max(max_left[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            max_right[i] = max(max_right[i + 1], height[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            int Min = min(max_left[i], max_right[i]);
            if (Min > height[i]) {
                sum = sum + (Min - height[i]);
            }
        }
        return sum;
    }
};

//双指针
//https://leetcode-cn.com/problems/trapping-rain-water/solution/dong-tai-gui-hua-shuang-zhi-zhen-tu-jie-by-ml-zimi/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxleft = height[0];
        int maxright = height[n-1];
        int ans = 0;

        while (left <= right){
            maxleft = max(height[left],maxleft);
            maxright = max(height[right],maxright);
            //小的向里收缩，则此时小的值(maxleft或者maxright) - height必定是水量高度。因为另一侧有比自己更大的值能够当边界。
            //类似 11. 盛最多水的容器 思想
            if(maxleft < maxright){
                ans += maxleft - height[left];
                left++;
            }
            else{
                ans += maxright - height[right];
                right--;
            }
        }
        return ans;
    }
};

//单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> s;
        int temp;
        int res = 0;
        for(int i=0;i<n;i++){
            while(!s.empty()&&height[s.top()]<=height[i]){
                temp = s.top();
                s.pop();
                if(!s.empty()){
                    //此时，height[s.top()]为temp左边的第一个比自己大的值，height[i]为temp右边第一个比自己大的值，有凹槽。
                    res += (min(height[s.top()],height[i]) - height[temp])*(i - s.top() - 1);
                }
            }
            s.push(i);
        }
        return res;
    }
};

