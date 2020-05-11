class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int>::iterator i;
	//int m = distance(nums1.begin(), find(nums1.begin(), nums1.end(),0 ));   //从iterator 到Int
    int count=0;
	int a[1000] = {0};
		for (auto x : nums1)
		{
            if (count == m)break;
			a[x+500]++;
            count++;
		}
		 for (auto x : nums2)
		 {
			 a[x+500]++;
		 }
		int j = -500;
		nums1.clear();
		for(j;j<500;j++)
		{
			while (a[j+500])
			{   
				nums1.push_back(j);
				a[j+500] -= 1;
			}
		}

}
};