class Solution {
public:
    string toGoatLatin(string S) {
        int cnt = 1;
        string ans;
        string temp;
        for (int i = 0; i <= S.length(); ++i){
            if (S[i] == ' ' || S[i] == '\0'){
                switch(temp[0]){
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                        ans += temp;
                        ans += "ma";
                        for (int j = 0; j < cnt; ++j){
                            ans.push_back('a');
                        }
                        if (S[i] != '\0')
                            ans.push_back(' ');
                        break;
                    default:
                        if (temp.length() > 1){
                        ans += temp.substr(1, temp.length()-1);
                        ans.push_back(temp[0]);
                        }
                        else {
                            ans += temp;
                        }
                        ans += "ma";
                        for (int j = 0; j < cnt; ++j){
                            ans.push_back('a');
                        }
                        if (S[i] != '\0')
                            ans.push_back(' ');
                        break;
                }
                temp.clear();
                ++cnt;
            }
            else{
                temp.push_back(S[i]);
            }
        }
        return ans;
    }
};