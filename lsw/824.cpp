class Solution {
public:
    string toGoatLatin(string S) 
    {
        unordered_set<char> yuan={'a','e','i','o','u','A','E','I','O','U'};
        string res="",word="",a="a";
        S+=" ";
        for(char ch:S)
        {
            if(ch==' ')
            {
                if(yuan.count(word[0]))
                {
                   res+=word;
                }   
                else
                {
                   res+=word.substr(1)+word[0];
                } 
                res+="ma"+a+' ';
                a+='a';
                word="";
            }
            else 
            {
               word+=ch;
            }
        }
        res.pop_back();
        return res;
        
    }
};
