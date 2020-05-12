class Solution {
public:
    string intToRoman(int num)
    {
        char* ch[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
        string roman;
        roman.append(ch[3][num / 1000]);
        roman.append(ch[2][num / 100 % 10]);
        roman.append(ch[1][num / 10 % 10]);
        roman.append(ch[0][num % 10]);
         
        return roman;
    }
};