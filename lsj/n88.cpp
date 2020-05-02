class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m + n - 1, p1 = m - 1, p2 = n - 1;
        while(p2 >= 0) {
            if(p1 == -1 || nums1[p1] < nums2[p2]) {
                nums1[cur--] = nums2[p2--];
            } else {
                nums1[cur--] = nums1[p1--];
            }
        }
    }
};
