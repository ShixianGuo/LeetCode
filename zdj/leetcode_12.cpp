#include <string>
#include <algorithm>
using namespace std;

class Solution {
    char dict[7];
public:
    Solution() {
        dict[0] = 'I';
        dict[1] = 'V';
        dict[2] = 'X';
        dict[3] = 'L';
        dict[4] = 'C';
        dict[5] = 'D';
        dict[6] = 'M';
    }
    string intToRoman(int num) {
        string result;
        int count = 0;
        while(num) {
            int cur = num % 10;
            if(cur < 4) {
                for(int i = 0; i < cur; i++)
                    result += dict[2*count];
            }
            else if(cur == 4) {

                result += dict[2*count + 1];
                result += dict[2*count];
            }
            else if(cur < 9) {

                for(int i = 0; i < cur - 5; i++)
                    result += dict[2*count];
                result += dict[2*count + 1];
            }
            else {

                result += dict[2*count + 2];
                result += dict[2*count];
            }
            count++;
            num /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
