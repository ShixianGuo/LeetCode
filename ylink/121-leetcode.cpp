class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        vector<int> left_min(prices.size());
        vector<int> right_max(prices.size());
        left_min[0] = 0;
        int min_index = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[min_index] > prices[i])
                min_index = i;
            left_min[i] = min_index;
        }
        
        right_max[prices.size() - 1] = prices.size() - 1;
        int max_index = prices.size() - 1;
        for(int i = prices.size() - 2; i >= 0; i--)
        {
            if(prices[max_index] < prices[i])
                max_index = i;
            right_max[i] = max_index;
        }
        int diff = prices[right_max[0]] - prices[left_min[0]];
        for(int i = 1; i < prices.size(); i++)
        {
            int new_diff = prices[right_max[i]] - prices[left_min[i]];
            if(diff < new_diff)
                diff = new_diff;
        }
        return diff;
    }
};
