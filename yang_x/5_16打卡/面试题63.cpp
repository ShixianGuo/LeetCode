class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int minnum = prices[0];	//定义一个变量保存遍历过的元素的最小值
        int maxfit = 0;	//定义变量保存当前最大利润
        int j = 1;	//定义一个指针从第1号位置的元素开始进行遍历
        while (j < prices.size()){
            if (prices[j] > minnum){	//如果当前元素大于前面的最小值，判断利润是否大于最大利润，大于则保存
                maxfit = max(maxfit, prices[j] - minnum);
            }
            else{	//如果当前元素小于前面的最小值，将最小值赋给最小值的变量
                minnum = prices[j];
            }
            ++j;
        }
        return maxfit;
    }
};