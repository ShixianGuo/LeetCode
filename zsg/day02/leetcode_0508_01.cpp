#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m,j=0; j < n; i++,j++) {
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }
};

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    Solution ss;
    ss.merge(nums1,3,nums2,3);
    return 0;
}