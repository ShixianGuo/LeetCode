class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int >a =nums1;
        int x=0,y=0;
        for(int i=0;i<m+n;i++)
        {
            if(x>=m)
            {
                nums1[i]=nums2[y++];
            }
            else if(y>=n)
            {
                nums1[i]=a[x++];
            }
            else if(a[x]>nums2[y])
            {
                nums1[i]=nums2[y++];
            }
            else
            {
                nums1[i]=a[x++];
            }
        }
    }
};