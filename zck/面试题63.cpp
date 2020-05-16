#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices){
    int min_price = INT32_MAX;
    int profit = 0;
    for(auto price : prices){
        min_price = min(price, min_price);
        profit = max(profit,  price - min_price);
    }
    return profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
    return 0;
}