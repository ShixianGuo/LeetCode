class Solution {
public:
    bool isIPv6(string& ip){
        int cnt = 0;
        string temp;
        for (int i = 0; i <= ip.length(); ++i){
            if (ip[i] == ':' || ip[i] == '\0'){
                if (temp.length() > 4 || temp.length() == 0)
                    return false;
                if (temp.length() == 1 && temp[0] != '0')
                    return false;
                /*if (temp.length() > 1 && temp[0] == '0')
                    return false;*/
                temp.clear();
                ++cnt;
            }
            else {
                if (temp[0] >= 'a' && temp[0] <= 'f')
                    temp.push_back(ip[i]);
                else if (temp[0] >= 'A' && temp[0] <= 'F')
                    temp.push_back(ip[i]);
                else 
                    return false;
            }
        }
        if (cnt != 8)
            return false;
        return true;
    }
    bool isIPv4(string& ip){
        if (ip.length() > 15){
            return false;
        }
        int cnt = 0;
        string temp;
        for (int i = 0; i <= ip.length(); ++i){
            if (ip[i] == '.' || ip[i] == '\0'){
                if (temp.length() == 0)
                    return false;
                if (temp.length() > 1 && temp[0] == '0')
                    return false;
                if (stoi(temp) > 255 || stoi(temp) < 0)
                    return false;
                temp.clear();
                ++cnt;
            }
            else {
                if (ip[i] >= '0' && ip[i] <= '9')
                    temp.push_back(ip[i]);
                else
                    return false;
            }
        }
        if (cnt != 4)
            return false;
        return true;
    }
    string validIPAddress(string IP) {
        if (IP.length() == 0)
            return "Neither";
        if (IP.length() < 7)
            return "Neither";
        if (IP.length() > 39)
            return "Neither";
        if (IP[4] == ':'){
            bool flag = true;
            flag = isIPv6(IP);
            if (flag == false)
                return "Neither";
            else
                return "IPv6";
        }
        else{
            bool flag = true;
            flag = isIPv4(IP);
            if (flag == false)
                return "Neither";
            else
                return "IPv4";
        }
        return "Neither";
    }
};