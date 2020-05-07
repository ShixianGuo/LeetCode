// @File   : 468_validIPAddress.cpp
// @Source : https://leetcode-cn.com/problems/validate-ip-address/
// @Title  : 468. 验证IP地址
// @Auther : sun_ds
// @Date   : 2020/5/6

/**  题目描述：
    编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址。

    IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；

    同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。

    IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。

    然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。

    同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。

    说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。

    示例 1:

    输入: "172.16.254.1"

    输出: "IPv4"

    解释: 这是一个有效的 IPv4 地址, 所以返回 "IPv4"。
    示例 2:

    输入: "2001:0db8:85a3:0:0:8A2E:0370:7334"

    输出: "IPv6"

    解释: 这是一个有效的 IPv6 地址, 所以返回 "IPv6"。
    示例 3:

    输入: "256.256.256.256"

    输出: "Neither"

    解释: 这个地址既不是 IPv4 也不是 IPv6 地址。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/validate-ip-address
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 恶心坏了。
 *
 * count统计sting中指定字符的个数
 * 指定字符分割字符串
 * stringstream ss
 * while (getline(ss, temp, 'c'))
 *
 * isdigit判断字符是否为数字
 *
 *
 */


class Solution {
public:
    string validIPAddress(string IP) {
        if(count(IP.begin(),IP.end(),'.')==3){ //IPv4包含3个.
            stringstream ss(IP);
            string temp;
            int count=0;
            while (getline(ss, temp, '.')){
                //长度为0和大于3都是不行的
                if(temp.size()==0||temp.size()>3) return "Neither";
                //temp必须全是数字
                for(int i=0;i<temp.size();i++) if(!isdigit(temp[i])) return "Neither";
                int t = atoi(temp.c_str());
                //数字在0~255
                if(t>255) return "Neither";
                    //处理非法0
                else if(temp[0]=='0'&&temp.size()!=1) return "Neither";
                count++;
            }
            //count 防止"1.0.1." 最后一部分没有的，切分不出来无法判断
            return count == 4 ? "IPv4" : "Neither";
        }else if(count(IP.begin(),IP.end(),':')==7){ //IPv6包含7个:
            stringstream ss(IP);
            string temp;
            int count=0;
            while (getline(ss, temp, ':')){
                //长度必须1~4直接
                if(temp.size()==0||temp.size()>4) return "Neither";
                //每一位属于0~f，包括大小写
                for(int i=0;i<temp.size();i++){
                    if(!(isdigit(temp[i]) ||  (temp[i]>='a'&& temp[i]<='f') || (temp[i]>='A'&&temp[i]<='F'))) return "Neither";
                }
                count++;
            }
            return count == 8 ? "IPv6" : "Neither";
        }else{
            return "Neither";
        }
    }
};

