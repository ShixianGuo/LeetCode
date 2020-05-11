#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<vector<string>> results;
    vector<int> queen_pos;
    int queen_num;
public:
    bool judge(int i, int j) {
        if(i < 0 || i >= queen_num || j < 0 || j >= queen_num)
            return false;
        for(int line = 0; line < i; line++) {
            if(abs(queen_pos[line] - j) == (i - line) || queen_pos[line] == j)
                return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        queen_num = n;
        queen_pos.resize(n);
        for(int i = 0; i < n; i++)
            queen_pos[i] = -1;
        recur(0);
        return results;
    }

    void recur(int i) {
        if(i == queen_num) {
            string tmp_str;
            vector<string> tmp_method;
            for(int j = 0; j < queen_num; j++)
                tmp_str += '.';
            for(int j = 0; j < queen_num; j++) {
                tmp_str[queen_pos[j]] = 'Q';
                tmp_method.push_back(tmp_str);
                tmp_str[queen_pos[j]] = '.';
            }
            results.push_back(tmp_method);
            return;
        }
        // Try every position in the line
        for(int j = 0; j < queen_num; j++) {
            if(judge(i, j)) {
                queen_pos[i] = j;
                recur((i+1));
                queen_pos[i] = -1;
            }
        }

    }
};

int main() {
    Solution tmp;
    tmp.solveNQueens(4);
}