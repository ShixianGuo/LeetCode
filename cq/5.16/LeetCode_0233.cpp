class Solution {
    int NumberOf1(string s,int idx){
        if(idx>=s.size()) return 0;
        int first=s[idx]-'0';
        int len=s.size()-idx;
        if(len==1&&first==0) return 0;
        if(len==1&&first>0) return 1;

        int numFirst=0;
        if(first>1) numFirst=(int)pow(10,len-1);
        else if(first==1) numFirst= stoi(s.substr(idx+1))+1; 

        int numOther=first*(len-1)*(int)pow(10,len-2);
        int numRecursive=NumberOf1(s,idx+1);

        return numFirst+numOther+numRecursive;
    }
public:
    int countDigitOne(int n) {
        if(n<1) return 0;
        string s=to_string(n);
        return NumberOf1(s,0);
    }
};