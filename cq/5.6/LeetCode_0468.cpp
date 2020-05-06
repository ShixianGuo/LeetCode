class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.find(':')!=-1) return isIPv6(IP);
        else return isIPv4(IP);
    }
    vector<string> split(string s,char c){
        int start=0;
        vector<string> res;
        while(1){
            auto end=s.find(c,start);
            if(end==-1) break;    
            res.emplace_back(s.substr(start,end-start));
            start=end+1;
        }
        res.emplace_back(s.substr(start));
        return res;
    }
    string isIPv6(string s){
        vector<string> v=split(s,':');
        if(v.size()!=8) return "Neither"; 
        for(auto it:v){
            if(it.size()>4||it.size()==0) return "Neither";
            for(int i=0;i<it.size();++i){
                if(!(isdigit(it[i])||(it[i]>='a'&&it[i]<='f')||(it[i]>='A'&&it[i]<='F'))) return "Neither";
            }
        }
        return "IPv6";
    }
    string isIPv4(string s){
        vector<string> v=split(s,'.');
        if(v.size()!=4) return "Neither"; 
        for(auto it:v){
            if((it.size()>1&&it[0]=='0')||it.size()>3||it.size()==0) return "Neither";
            for(int i=0;i<it.size();++i){
                if(!(isdigit(it[i]))) return "Neither";
            }
            int num=stoi(it);
            if(num>255) return "Neither";
        }
        return "IPv4";
    }
};