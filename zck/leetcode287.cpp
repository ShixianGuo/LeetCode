class Solution {
public:

int findDuplicate(vector<int>& nums){
    unordered_map<int, int> m;
    for(auto num : nums){
        m[num]++;
        if(m[num] == 2)
            return num;
    }
    return -1;
}
};