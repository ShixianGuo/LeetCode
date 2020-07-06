#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int singleNumber(vector<int>& nums){
    unordered_map<int, int> m;
    for(auto num : nums){
        m[num] += 1;
    }
    for(auto ptr = m.begin(); ptr != m.end(); ptr++)
        if(ptr->second == 1)
            return ptr->first;
    return 0;
}

int main(){
    vector<int> nums = {0,1,0,1,0,1,99};
    cout << singleNumber(nums) << endl;;

    return 0;
}