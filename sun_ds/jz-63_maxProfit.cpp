// @File   : jz-63_maxProfit.cpp
// @Source : https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
// @Title  : 面试题63. 股票的最大利润
// @Auther : sun_ds
// @Date   : 2020/5/16

/**  题目描述：
    假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

     

    示例 1:

    输入: [7,1,5,3,6,4]
    输出: 5
    解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
         注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
    示例 2:

    输入: [7,6,4,3,1]
    输出: 0
    解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
     

    限制：

    0 <= 数组长度 <= 10^5

     

    注意：本题与主站 121 题相同：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/



    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.单调递增栈 vector实现
 *  prices放入标兵。使得最后一波最大值能够出栈。
 *  若当前值小于栈顶，则栈顶出栈，并计算利润 = 栈顶 - 栈底。
 *  记录过程中最大利润
 *
 * 2.记录过程中最小值
 * 当前价格减记录的最小值即为利润
 * 记录过程中最大利润
 *
 *
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> count;
        int res = 0;
        prices.push_back(-1); //使所有元素出栈被计算
        for(int i=0;i<prices.size();i++){
            while(!count.empty()&&count.back()>prices[i]){
                int temp = count.back() - count.front();
                res = max(res,temp);
                count.pop_back();
            }
            count.push_back(prices[i]);
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_price = INT_MAX;
        for(int i=0;i<prices.size();i++){
            min_price = min(prices[i],min_price);
            res = max(res,prices[i] - min_price);
        }
        return res;
    }
};