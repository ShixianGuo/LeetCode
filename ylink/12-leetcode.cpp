class Solution {
public:
    string intToRoman(int num) {
        string answer = "";
        if(num >= 1000){          
             //int temp = num % 1000;
            int noOfTimes = num / 1000;
            while(noOfTimes--){
                answer += "M";
            }
            num = num % 1000;
            
        }
        if(num >= 900){
            answer += "CM";
            num = num % 900;
        }
        if(num >= 500){
            int temp = num % 500;
            int noOfTimes = temp / 100;
            answer += "D";
            int times = noOfTimes;
            while(noOfTimes--){
                answer += "C";
            }
            //answer += "D";
            num = num % (500 + times * 100);
        }
        if(num >= 400){
            answer += "CD";
            num = num % 400;
        }
        if(num >= 100){
            //int temp = num % 100;
            int noOfTimes = num / 100;
            
            while(noOfTimes--){
                answer += "C";

            }
            num = num % 100;
        }
        if(num >= 90){
            answer += "XC";
            num = num % 90;
        }
        if(num >= 50){
            int temp = num % 50;
            int noOfTimes = temp / 10;
            int temptimes = noOfTimes;
            answer += "L";
            while(temptimes--){
                answer += "X";
            }
            num = num % (50 + noOfTimes * 10);
        }
        if(num >= 40){
            answer += "XL";
            num = num % 40;
        }
        if(num >= 10){
            int temp = num / 10;
            int noOfTimes = temp;
            while(noOfTimes--){
                answer += "X";
            }
            num = num % 10;
        }
        if(num >= 9){
            answer += "IX";
            num = num % 9;
        }
        if(num >= 5){
            int temp = num % 5;
            answer += "V";
            int noOfTimes = temp;
            int no = noOfTimes;
            while(noOfTimes--){
                answer += "I";
            }
            num = num % (5 + no * 1);
        }
        if(num >= 4){
            answer = answer + "IV";
        }
        else{
            while(num--){
                answer += "I";
            }
        }
        return answer;
    }
};
