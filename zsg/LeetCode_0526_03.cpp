#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void ADD(set<string>& s, set<string>& s1) {
        for (auto x : s1) {
            s.insert(x);
        }
        s1.clear();
    }
    void MUL(set<string>& s, const set<string>& s1) {
        if (s1.empty()) return;
        if (s.empty()) {
            s = s1;
            return;
        };
        set<string> s2;
        for (auto t : s) {
            for (auto t1 : s1) {
                s2.insert(t + t1);
            }
        }
        swap(s, s2);
    }
    void MUL(set<string>& s, string& t) {
        if (t.empty()) return;
        if (s.empty()) {
            s = { t };
            t.clear();
            return;
        }
        set<string> s1;
        for (auto x : s) {
            s1.insert(x + t);
        }
        t.clear();
        swap(s, s1);
    }
    set<string> parse(const string& exp, int l, int r) {
        set<string> res;
        set<string> s;
        string t;
        int i = l;
        while (i <= r) {
            if (exp[i] == ',') {
                MUL(s, t);
                ADD(res, s);
            }
            else if (exp[i] == '{') {
                int l = i;
                int brace = 1;
                while (brace > 0 && ++i <= r) {
                    brace += exp[i] == '{';
                    brace -= exp[i] == '}';
                }
                MUL(s, t);
                MUL(s, parse(exp, l + 1, i - 1));
            }
            else {
                t += exp[i];
            }
            ++i;
        }
        MUL(s, t);
        ADD(res, s);
        return res;
    }
    vector<string> braceExpansionII(string expression) {
        auto s = parse(expression, 0, expression.size() - 1);
        return vector<string>(s.begin(), s.end());
    }
};
