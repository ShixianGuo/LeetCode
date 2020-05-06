class Solution {
public:
    string validIPAddress(string IP) 
    {
        if(isValidIPv4(IP))
        {
            return "IPv4";
        }
        else if(isValidIPv6(IP))
        {
            return "IPv6";
        }
        else
        {
            return "Neither";
        }
    }
    
    bool isValidIPv4(string ip)
    {
        vector<int> dot_pos;
        for(auto it = ip.begin(); it < ip.end(); it++)
        {
            if(*it == '.')
            {
                dot_pos.push_back(it - ip.begin());
            }
        }
        if(dot_pos.size() != 3)
        {
            return false;
        }
        vector<string> numstr;
        numstr.push_back(ip.substr(0, dot_pos[0]));
        numstr.push_back(ip.substr(dot_pos[0] + 1, dot_pos[1] - dot_pos[0] - 1));
        numstr.push_back(ip.substr(dot_pos[1] + 1, dot_pos[2] - dot_pos[1] - 1));
        numstr.push_back(ip.substr(dot_pos[2] + 1, ip.size() - dot_pos[2] - 1));

        for(const auto& e : numstr)
        {
            if(e.empty())
            {
                return false;
            }
            if(e.size() > 1 && e[0] == '0')
            {
                return false;
            }
            auto it = find_if(e.begin(), e.end(), [](const char& c){ return !isdigit(c);});
            if(it != e.end())
            {
                return false;
            }
            try {
                int num(stoi(e));
                if(num < 0 || num > 255)
                {
                    return false;
                }
            } catch(...) {
                return false;
            }
        }
        return true;
    }
    
    bool isValidIPv6(string ip)
    {
        set valid_alpha{'a', 'b', 'c', 'd', 'e', 'f'};
        int how_many_chunks = 0;
        auto last_colon_pos = -1;
        for(int i = 0; i < ip.size() + 1; i++)
        {
            if(i < ip.size())
            {
                ip[i] = tolower(ip[i]);
                if(ip[i] == ':')
                {
                    string chunk = ip.substr(last_colon_pos + 1, i - last_colon_pos - 1);
                    if(chunk.size() > 4 || chunk.empty())
                    {
                        return false;
                    }
                    last_colon_pos = i;
                    auto it = find_if(chunk.begin(), chunk.end(), [&](const char& c){ return (valid_alpha.find(c) == valid_alpha.end()) && !isdigit(c);});
                    if(it != chunk.end())
                    {
                        return false;
                    }

                    how_many_chunks++;
                }
            }
            else
            {
                string chunk = ip.substr(last_colon_pos + 1, ip.size() - last_colon_pos - 1);
                if(chunk.size() > 4 || chunk.empty())
                {
                    return false;
                }
                last_colon_pos = i;
                auto it = find_if(chunk.begin(), chunk.end(), [&](const char& c){ return (valid_alpha.find(c) == valid_alpha.end()) && !isdigit(c);});
                if(it != chunk.end())
                {
                    return false;
                }
                how_many_chunks++;
            }
        }
        return how_many_chunks == 8;
        
    }
};
