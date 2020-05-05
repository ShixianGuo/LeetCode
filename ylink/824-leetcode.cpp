class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string t;
        string res;
        set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int how_many_word = 0;
        while(ss >> t)
        {
            how_many_word++;
            //consonant case
            if(vowels.find(t[0]) == vowels.end())
            {
                rotate(t.begin(), t.begin() + 1, t.end());
            }
            t += "ma";
            for(int i = 0; i < how_many_word; i++)
            {
                t += "a";
            }
            res += t;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};
