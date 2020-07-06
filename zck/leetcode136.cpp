#include <iostream>
#include <vector>

using namespace std;

/*
任何数和 00 做异或运算，结果仍然是原来的数，即 a \oplus 0=aa⊕0=a。
任何数和其自身做异或运算，结果是 00，即 a \oplus a=0a⊕a=0。
异或运算满足交换律和结合律，即 a \oplus b \oplus a=b \oplus a \oplus a=b \oplus (a \oplus a)=b \oplus0=ba⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b
*/
int singleNumber(vector<int>& nums){
    int ret = 0;
    for(auto num : nums)
        ret ^= num;
    return ret;
}
