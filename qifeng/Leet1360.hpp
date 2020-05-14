/*
请你编写一个程序来计算两个日期之间隔了多少天。

日期以字符串形式给出，格式为 YYYY-MM-DD，如示例所示。

 

示例 1：

输入：date1 = "2019-06-29", date2 = "2019-06-30"
输出：1
示例 2：

输入：date1 = "2020-01-15", date2 = "2019-12-31"
输出：15
 

提示：

给定的日期是 1971 年到 2100 年之间的有效日期。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-days-between-two-dates
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int days[13]={0, 31,28,31,30,31,30,31,31,30,31,30,31};
    bool extraDay(int year){
        return (year%400==0)||(year%4==0&&year%100!=0);
    }
    //该日期到1971-1-1间隔天数
    int dateToInt(string date){
        int year, mouth, day;
        sscanf(date.c_str(), "%d-%d-%d",&year, &mouth, &day);
        int ans=day-1;
        while(mouth>0){
            --mouth;
            ans+=days[mouth];
            if(mouth==2&&extraDay(year)) ans++;
        }
        ans+=365*(year-1971);
        //假设4的倍数都i是闰年
        ans+=((year-1)/4-1971/4);
        //多加了，减去100的倍数
        ans-=((year-1)/100-19);
        //多减了，加上400的倍数
        ans+=((year-1)/400-1971/400);
        return ans;
    }
    int daysBetweenDates(string date1, string date2) {

        return abs(dateToInt(date1) - dateToInt(date2));
    }
};