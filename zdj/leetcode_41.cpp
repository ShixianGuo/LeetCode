#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] != i + 1) {
                if (nums[i] < 1 || nums[i] > nums.size() || nums[nums[i] - 1] == nums[i])
                    break;
                int tmp = nums[i];
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
            }
        }
        int result;
        for(result = 0; result < nums.size(); result++) {
            if(nums[result] != result + 1)
                return result + 1;
        }
        return nums.size() + 1;
    }
};
