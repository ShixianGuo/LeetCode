class Solution {
    unordered_map<int, bool> record;
public:
    int convert(int src) {
        int count = 0;
        while(src) {
            count += (src % 10) * (src % 10);
            src /= 10;
        }
        return count;
    }

    bool isHappy(int n) {
        while(n != 1) {
            if(record.find(n) != record.end())
                return false;
            else
                record[n] = true;
            n = convert(n);
        }
        return true;
    }
};
