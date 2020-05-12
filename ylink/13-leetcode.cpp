class Solution {
private:
    static const unordered_map<string, int> sMap;
    
    static auto substraction_case(char cur, char next) -> bool {
	    switch (cur){
		    case 'I': return next == 'V' || next == 'X';
		    case 'X': return next == 'L' || next == 'C';
		    case 'C': return next == 'D' || next == 'M';
		    default: return false;
	    }
    }
    
public:
    int romanToInt(string s) {        
        int res{}; size_t const len{ s.size() };

        for (size_t i{}; i < len; ++i)
        {
            auto const nb = sMap.find(std::string{ s[i] })->second;
	        bool const should_substract = (i != len - 1 && substraction_case(s[i], s[i + 1]));	
	        
            res += should_substract ? -nb : nb;
        }
        return res;
    }
};

unordered_map<string, int> const Solution::sMap = {
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000}
};
