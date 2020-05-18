class Solution {
public:
    void reversea(int front, int tail, string& str)
    {
        while (front < tail) {
            str[front] ^= str[tail];
            str[tail] ^= str[front];
            str[front++] ^= str[tail--];
        }
    }
    
    string reverseWords(string s) {
        int a=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                reversea(a,i-1,s);
                a=i+1;
            }
        }
        reversea(a,s.length()-1,s);
        return s;
    }
};