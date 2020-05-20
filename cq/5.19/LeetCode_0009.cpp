class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else if(x<10) return true;
        else if(x%10 == 0) return false;
        else{
            int nums[10]={0};
            int i=0;
            while(x){
                nums[i++]=x%10;
                x/=10;
            }
            int j=0;
            --i;
            while(j<=i)
                if(nums[j++]!=nums[i--]) return false;
            return true;
        }
    }
};