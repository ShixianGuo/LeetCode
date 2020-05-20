class Solution {
public:
    string reverseWords(string s) {
        stringstream sin;
        string word_cache;
        string res;
        sin << s;
        while(sin >> word_cache)
        {
            reverse(word_cache.begin(), word_cache.end());
            res += word_cache;
            res += ' ';
        }
        if(res.size() > 0)
             res.replace(res.size() - 1, 1, "");
        return res;
    }
};
