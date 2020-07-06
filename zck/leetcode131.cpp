class Solution {
    vector<vector<string>> res;
    int size;
    bool check(const string&s, int i, int j) {
        if (j < i) return true;
        if (s[i++] == s[j--]) return check(s, i, j);
        else return false;
    }
    void backtrack(const string& s, int ps, vector<string>& temp) {
        if (ps >= size) {
            res.push_back(temp);
            return;
        }
        for (int i = ps; i < size; ++i) {
            if (check(s, ps, i)) {
                temp.push_back(s.substr(ps, i-ps+1));
                backtrack(s, i+1, temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(const string& s) {
        size = s.size();
        if (size == 0) return res;
        vector<string> temp;
        backtrack(s, 0, temp);
        return res;
    }
};
