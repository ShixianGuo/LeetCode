/*
面试题51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:

输入: [7,5,6,4]
输出: 5
 

限制：

0 <= 数组长度 <= 50000

离散化+树状数组
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <stack>
using namespace std;


class Solution {
    vector<int> b;
    int get(int v){
        return lower_bound(b.begin(),b.begin()+bn,v)-b.begin();
    }
    int buf[50005];
    int lowbit(int x){
        return x&(-x);
    }

    void update(int x,int idx){
        while(idx<=50005){
            buf[idx]+=x;
            idx+=lowbit(idx);
        }
    }
    int getSum(int x){
        int res=0;
        while(x>0){
            res+=buf[x];
            x-=lowbit(x);
        }
        return res;
    }
    int bn=0;

public:
    int reversePairs(vector<int>& nums) {
        memset(buf,0,50005*sizeof(int));
        b=nums;
        int maxvalue=0;
        sort(b.begin(),b.end());
        bn=unique(b.begin(),b.end())-b.begin();
        for(int i=0;i<nums.size();i++){
            int x=get(nums[i])+1;
            update(1,x);
            maxvalue+=i+1-getSum(x);
        }
        return maxvalue;
    }
};



int main(){}




