class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
        {
            return 0;
        }
        bool neg_flag = x < 0;
        try {
            string s(to_string(x));
            if(neg_flag)
            {
                std::reverse(s.begin() + 1, s.end());
                while(s.size() >= 2 && s[1] == '0')
                    s.erase(s.begin() + 1);
            }
            else
            {
                std::reverse(s.begin(), s.end());
                while(s.size() >= 1 && s[0] == '0')
                    s.erase(s.begin());
            }
            return stoi(s);
        } catch(...) {
            return 0;
        }
    }
};
