#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
using namespace std;

class Solution {
    const string codeTable = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    unordered_map<string, string> storeURL;

    string getKey() {
        srand((unsigned long)time(NULL));
        string code;
        for(int i = 0; i < 6; i++)
            code += codeTable[rand() % 62];
        return move(code);
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = getKey();
        while(storeURL.find(key) != storeURL.end())
            key = getKey();
        storeURL[key] = longUrl;
        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.replace(0, string("http://tinyurl.com/").length(), "");
        return storeURL[key];
    }
};

