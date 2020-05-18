class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		if (n > m)
			return findMedianSortedArrays(nums2, nums1);
        int mid=(n+m+1)/2;
        int m1,m2,l=0,r=n;
        while(l<r)
        {
            m1=(l+r)/2;
            m2=mid-m1;
            if(nums1[m1]<nums2[m2-1])
                l=m1+1;
            else 
                r=m1;
        }
        m1 = l;
        m2 = mid-l;
        int c1 = max(m1 <= 0 ? INT_MIN:nums1[m1-1],
                    m2 <= 0 ? INT_MIN:nums2[m2-1]);
        if((n +m)%2 == 1)
            return c1;
        int c2 = min(m1 >= n ? INT_MAX: nums1[m1],
                    m2 >= m ? INT_MAX : nums2[m2]);
        return (c1 + c2) * 0.5;
	}
};