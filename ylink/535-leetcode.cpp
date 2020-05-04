class Solution {
public:
    Solution()
    {
        for(auto i = 'a'; i <= 'z'; i++)
        {
            tiny_url_chars.push_back(i);
            tiny_url_chars.push_back(i - ('a' - 'A'));
        }
        for(auto i = '0'; i <= '9'; i++)
        {
            tiny_url_chars.push_back(i);
        }
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        string random_postfix(get_random_str());
        random_postfix += "/";
        string res_url = string("http://tinyurl.com/") + random_postfix;
        url_mp[res_url] = longUrl;
        return res_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return url_mp[shortUrl];
    }
private:
    string get_random_str() const
    {
        string s;
        while(s.size() < tiny_url_len)
        {
            s.push_back(tiny_url_chars[rand() % tiny_url_chars.size()]);
        }
        return s;
    }
    unordered_map<string, string> url_mp;
    vector<char> tiny_url_chars;
    static const int tiny_url_len = 6;
};

//优化思路：map中不存http前缀……具体实现懒得做了

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
