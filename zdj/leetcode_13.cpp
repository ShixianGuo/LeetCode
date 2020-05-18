#include <string>
using namespace std;
class Solution {
public:
    int get_value(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int result = 0;
        int last_value = 0;
        for(auto& c : s) {
            result += get_value(c);
            if(last_value < get_value(c))
                result -= 2*last_value;
            last_value = get_value(c);
        }
        return result;
    }
};

