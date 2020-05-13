// @File   : 93_restoreIpAddresses.cpp
// @Source : https://leetcode-cn.com/problems/restore-ip-addresses/
// @Title  : 93. 复原IP地址
// @Auther : sun_ds
// @Date   : 2020/5/13

/**  题目描述：
    给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

    示例:

    输入: "25525511135"
    输出: ["255.255.11.135", "255.255.111.35"]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/restore-ip-addresses
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 复原IP地址
 *
 * 回溯法
 * 1.结束条件
 * 2.循环
 * 3.满足条件，记录，继续递归
 *
 * IP地址约束：
 * 1.必须刚好四段
 * 2.每一段范围[0,255]
 * 3.注意处理连续的0，即每个0字符只能成一段
 *
 * 结束条件:有四段了并且字符串刚好用完
 * 循环:段长度1~3
 * 约束条件:当前段在[0,255]之间，记录，继续递归
 *
 * 输入参数：b当前段起始位置 t为当前为第几段
 *
 *
 */


class Solution {
public:
    vector<string> ans;
    string s;
    array<string,4> a;//临时存储各分段
    //b当前段起始位置 t为当前为第几段
    void func(int b,int t){
        if(t==4) {
            if(b==s.size())
                ans.push_back(a[0] + '.' + a[1] + '.' + a[2] + '.' + a[3]);
            else
                return ;
        }
        int temp = 0;
        if(s[b]=='0'){ //单独的0为一个分段
            a[t] = to_string(0);
            func(b+1,t+1);
        }else{ //遍历取1,2,3位数，且都有小于等于255
            for(int i=b;i<b+3&&i<s.size();++i){
                temp = temp * 10 + s[i] - '0';
                if(temp>255) break;
                a[t] = to_string(temp);
                //起始位置后移，段数+1
                func(i+1,t+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        func(0,0);
        return ans;
    }
};