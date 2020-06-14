class Solution {
public:
   string longestPalindrome(string s) {
    if(s.empty()){
        return s;
    }
    string newStr;
    newStr.resize(s.size() * 2 + 1);
    vector<int> vec(s.size() * 2 + 1, -1);
    for(int i = 0; i < s.size(); ++i){
        newStr[2*i] = '#';
        newStr[2*i + 1] = s[i];
    }
    newStr[s.size() * 2] = '#';
    for(int i = 0; i < newStr.size(); ){
        if(vec[i] != -1){
            ++i;
            continue;
        }
        int p = 0;
        int left = i - 1;
        int right = i + 1;
        while(left >= 0 && right < newStr.size()){
            if(newStr[left] != newStr[right]){
                break;
            }
            ++p;
            --left;
            ++right;
        }
        vec[i] = p;
        int start = i - p;
        for(int j = start; j < i; ++j){
            int corres = 2 * i - j;
            if(j - vec[j] > start){
                vec[corres] = vec[j];
            }
            else if(j - vec[j] < start){
                vec[corres] = j - start;
            }
        }
    }
    int Max = 0;
    int pos = 0;
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] > Max){
            Max = vec[i];
            pos = i;
        }
    }
    string res;
    for(int i = pos - Max; i <= pos + Max; ++i){
        if(newStr[i] != '#'){
            res.push_back(newStr[i]);
        }
    }
    return res;
}
};
