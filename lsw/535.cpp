class Solution {

private:
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<string, string> m_map;
    string key = getRand();

     string getRand() {
        string res="";
        for (int i = 0; i < 6; i++) {
            res += alphabet[rand()%62];
        }
        return res;
    }




public:
     string encode(string longUrl) {
        while (m_map.find(key)!=m_map.end()) {
            key = getRand();
        }
        m_map[key] = longUrl;
        return "http://tinyurl.com/" + key;
    }

     string decode(string shortUrl) {
        return m_map[shortUrl.substr(19, shortUrl.length()-18)];
    }


};
