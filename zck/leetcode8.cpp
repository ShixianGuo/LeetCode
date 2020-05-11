class Solution {
public:
    int myAtoi(string s){
        int i;
        for(i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                continue;
            else
                break;
        }
        s  = s.substr(i);
        int flag = 1;
        if(s[0] == '-'){
            flag = -1;
            s = s.substr(1);
        }
        else if(s[0] == '+')
            s = s.substr(1);

        int k;
        for(k = 0; k < s.size(); k++){
            if(s[k] < '0' || s[k] > '9')
                break;
        }
        s = s.substr(0, k);
        if(s == "")
            return 0;

        int p;
        for(p = 0; p < s.size(); p++){
            if(s[p] != '0')
                break;
        }
        s = s.substr(p);
        if(s.size() > 10 && flag == 1)
            return INT32_MAX;
        if(s.size() > 10 && flag == -1)
            return INT32_MIN;

        

        long res = 0;
        for(int t = 0; t < s.size(); t++){
            res = res * 10 + (s[t] - '0');
        }
        res = res * flag;
        if(res > INT32_MAX)
            return INT32_MAX;
        if(res < INT32_MIN)
            return INT32_MIN;
        return res;
    }
};