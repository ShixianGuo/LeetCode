class Solution {
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string,string> mp;
    string key=getRand();
    string getRand(){
        string s;
        srand((int)(time(NULL)));
        for(int i=0;i<6;++i){
            s.push_back(alphabet[rand()%62]);
        }
        return s;
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while(mp.find(key)!=mp.end()) key=getRand();
        mp[key]=longUrl;
        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl.erase(0,19)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));