class Solution {
    int mouths[12]={31,28,31,30,31,30,31,31,30,31,30,31};
public:
    int f(string data){
        int year=stoi(data.substr(0,4));
        int mouth=stoi(data.substr(5,2));
        int day=stoi(data.substr(8,2));
        int res=0;
        for(int i=1970;i<year;++i){
            res+=365;
            if(i%400==0||(i%100!=0&&i%4==0)) res+=1;
        }
        for(int i=1;i<mouth;++i){
            res+=mouths[i-1];
            if(i==2&&(year%400==0||(year%100!=0&&year%4==0))) res+=1;
        }
        res+=day-1;
        return res;
    }
    int daysBetweenDates(string date1, string date2) {
        int f1=f(date1);
        int f2=f(date2);
        return abs(f1-f2);
    }
};