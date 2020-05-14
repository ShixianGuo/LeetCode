/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

 

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<string> ans;
    string ip;
    void popIP(int k){
        while(k>0){
            ip.pop_back();
            --k;
        }
    }
    void backTrace(const string &s, int begin, int num){
        int remain=s.size()-begin;
        //回溯边界
        if(num==0&&remain>0) return;
        if(num==1){
            if(remain>3) return;
            string str=s.substr(begin);
            if(str.size()>1&& str[0]=='0') return;
            if(atoi(str.c_str())>255) return;
            ip+=str;
            ans.push_back(ip);
            popIP(str.size());
        }

        for(int i=1;i<=3;++i){
            string str=s.substr(begin,i);
            //针对01，直接失败，不用看i=3的情况了
            if(str.size()>1&& str[0]=='0') return;
            --remain;
            //如果剩余坑位不足以填满剩余数字
            //如果剩余数字填不满坑位
            //如果数字大于255都失败
            if( (remain<=(num-1)*3) 
            && (remain>=num-1)
            && (i<3||atoi(str.c_str())<=255)){
                ip+=(str+'.');
                backTrace(s, begin+i, num-1);
                //需要将刚加入的pop掉
                popIP(str.size()+1);
            } 
        }

    }

    vector<string> restoreIpAddresses(string s) {
        //回溯
        backTrace(s, 0, 4);
        return ans;
    }
};