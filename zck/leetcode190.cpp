/*
颠倒给定的 32 位无符号整数的二进制位。

 

示例 1：

输入: 00000010100101000001111010011100
输出: 00111001011110000010100101000000
解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
     因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
*/

#include <iostream>
#include <vector>

using namespace std;

uint32_t reverseBits(uint32_t n){
    uint32_t res = 0;
    uint32_t left_shift = 31;
    while(n > 0){
        res += (n & 1) << left_shift;
        left_shift--;
        n = n >> 1;
    }
    return res;
}