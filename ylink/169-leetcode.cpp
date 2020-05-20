class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        if(is_sorted(nums.begin(), nums.end()))
            return nums[nums.size() / 2];
        else
            return majority_element(nums, 0, nums.size() - 1);
    }
    
    int majority_element(vector<int>& nums, int l, int r)
    {
        int i = l, j = r, x = nums[l];
        while(i < j)
        {
            while(i < j && nums[j] >= x)
                j--;
            if(i < j)
            {
                nums[i] = nums[j];
                i++;
            }
            while(i < j && nums[i] < x)
                i++;
            if(i < j) 
            {
                nums[j] = nums[i];
                j--;
            }
        }
        nums[i] = x;
        if(i == nums.size() / 2)
            return nums[i];
        else if(i > nums.size() / 2)
            return majority_element(nums, l, i - 1);
        else
            return majority_element(nums, i + 1, r);
    }
};
