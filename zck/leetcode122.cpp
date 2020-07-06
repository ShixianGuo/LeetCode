#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices){
    int max_profit = 0;

    for(int i = 1; i < prices.size(); i++){
        max_profit += max(prices[i]-prices[i-1], 0);
    }
    return max_profit;
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;

    return 0;
}