class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        if(n == 0 || n == 1)
        {
            return true;
        }
        else
        {
            int last_bit = !(n % 2);
            n >>= 1;
            while(n != 0)
            {
                int current_bit = !(n % 2);
                if(current_bit == last_bit)
                {
                    return false;
                }
                last_bit = current_bit;
                n >>= 1;
            }
            return true;
        }
    }
};
