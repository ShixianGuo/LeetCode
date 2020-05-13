// @File   : 1360_daysBetweenDates.cpp
// @Source : https://leetcode-cn.com/problems/number-of-days-between-two-dates/
// @Title  : 1360. 日期之间隔几天
// @Auther : sun_ds
// @Date   : 2020/5/13

/**  题目描述：
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

/**
 *
 * 计算两个日期之间的间隔。
 * 1.
 * 比较两个日期的大小大的日期在后面。
 * 先计算年份，非闰年365天，闰年366天。从起始年份计算到结束年前一年。
 * 减去起始年份的月份和日期，加上结束年份的月份和日期。注意判断是否是闰年，若是闰年2月份是29天。
 *
 * 2.不用比较日期大小
 * 全部求与1970-01-01之间的间隔天数。
 * 然后求起始和结束时间与1970-01-01间隔的绝对值即为所求值。
 *
 *
 * 使用sscanf格式化分割字符串
 * 使用stringstream分割字符串
 *
 * 闰年判断: year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0)
 *
 */

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {

        if(date1 > date2) swap(date1,date2);

        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        stringstream ss1(date1);
        string temp1;
        vector<int> d1;
        while(getline(ss1,temp1,'-')){
            d1.push_back(stoi(temp1.c_str()));
        }

        stringstream ss2(date2);
        string temp2;
        vector<int> d2;
        while(getline(ss2,temp2,'-')){
            d2.push_back(stoi(temp2.c_str()));
        }

        int res = 0;
        for(int i=d1[0];i<d2[0];i++){
            if(i%4==0&&(i%100!=0||i%400==0)) res+=1;
            res += 365;
        }

        for(int i=1;i<d1[1];i++){
            if(i==2 && (d1[0]%4==0&&(d1[0]%100!=0||d1[0]%400==0))) res -= 1;
            res -= days[i-1];
        }
        res -= d1[2];

        for(int i=1;i<d2[1];i++){
            if(i==2 && (d2[0]%4==0&&(d2[0]%100!=0||d2[0]%400==0))) res += 1;
            res += days[i-1];
        }
        res += d2[2];

        return res;
    }
};


class Solution {
    bool leap_year(int year) {
        return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
    }
    int date_to_int(string date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        int month_length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = day - 1;
        while (month != 0) {
            --month;
            ans += month_length[month];
            if (month == 2 && leap_year(year))
                ans += 1;
        }
        ans += 365 * (year - 1971);
        ans += (year - 1) / 4 - 1971 / 4;
        ans -= (year - 1) / 100 - 1971 / 100;
        ans += (year - 1) / 400 - 1971 / 400;
        return ans;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(date_to_int(date1) - date_to_int(date2));
    }
};

