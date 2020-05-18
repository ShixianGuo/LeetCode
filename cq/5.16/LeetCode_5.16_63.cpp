class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int minNum=prices[0];
        int maxDiff=prices[1]-minNum;
        for(int i=2;i<prices.size();++i){
            if(prices[i-1]<minNum) minNum=prices[i-1];
            int curDiff=prices[i]-minNum;
            maxDiff=max(maxDiff,curDiff);
        }
        return maxDiff>0?maxDiff:0;
    }
};