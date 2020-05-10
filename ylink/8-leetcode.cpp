class Solution {
public:
    int myAtoi(string str) {
        auto it = find_if(str.begin(), str.end(), [](const char& c) { return !isspace(c);});
        set<char> syms{'+', '-'};
        set<char> nums{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        if(it == str.end() || (syms.find(*it) == syms.end() && nums.find(*it) == nums.end()))
        {
            return noValidConversion();
        }
        else
        {
            bool neg_flag = false;
            if(*it == '-')
            {
                neg_flag = true;
            }
            if(syms.find(*it) != syms.end())
            {
                it++;
            }
            auto end_it = find_if(it, str.end(), [](const char& c) { return !isdigit(c);});
            if(it == end_it)
            {
                return noValidConversion();
            }
            str = str.substr(it - str.begin(), end_it - it);
            if(str == "2147483648" && neg_flag)
            {
                return INT_MIN;
            }
            long long val = *str.begin() - '0';
            end_it = find_if(str.begin(), str.end(), [](const char& c) { return !isdigit(c);});
			for (auto i = str.begin() + 1; i < end_it; i++)
            {
                val *= 10;
                val += (*i - '0');
                if(val > INT_MAX)
                {
                    if(neg_flag)
                    {
                        return INT_MIN;
                    }
                    else
                    {
                        return INT_MAX;
                    }
                }
            }
            if(neg_flag)
            {
                val *= -1;
            }
            return val;
        }
    }
private:
    int noValidConversion() {
        return 0;
    }    
};
