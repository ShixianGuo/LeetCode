#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

/* "2019-06-29", date2 = "2019-06-30" */

bool isLeapYear(int year){
    if(year % 4 == 0 || year % 100 != 0 && year % 4 == 0)
        return true;
    return false;
}

int getDays(string date){

    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    int ans = 0;
    for(int i = 1971; i < year; i++){
        if(isLeapYear(i))
            ans += 366;
        else
            ans += 365;
    }

    for(int j = 1; j < month; j++){
        if(j == 2 && isLeapYear(year))
            ans += 29;
        else{
            ans += days[j - 1];
        }
    }
    ans += day;
    return ans;
}

int daysBetweenDates(string date1, string date2){
    return getDays(date2) - getDays(date1);
}
 
int main(){

    string date1 = "2020-01-15";
    string date2 = "2019-12-31";
    
    if(date1 > date2)
        swap(date1, date2);
    cout << daysBetweenDates(date1, date2) << endl;
    
    return 0;
}
