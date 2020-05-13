class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(getdate(date1) - getdate(date2));
    }

    int getdate(string date) {
        int month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int year, month, day, ans = 0;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        for (int i = 0; i < year; ++i) 
            if (i % 400 == 0 || i % 4 == 0 && i % 100) ans += 366;
        else ans += 365;
        if (year % 400 == 0 || year % 4 == 0 && year % 100) month_day[2] = 29;
        for (int i = 0; i < month; ++i) ans += month_day[i];
        ans += day;
        return ans;
    }
};