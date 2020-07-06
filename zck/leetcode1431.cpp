#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
    vector<bool> res(candies.size(), false);
    int max_val = candies[0];
    for(auto candy : candies)
    
        max_val = max(candy, max_val);
    for(int i = 0; i < candies.size(); i++){
        if(candies[i] + extraCandies >= max_val)
            res[i] = true;
    }
    return res;
}