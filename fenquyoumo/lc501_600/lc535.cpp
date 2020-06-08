class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        reverse(longUrl.begin(),longUrl.end());
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        reverse(shortUrl.begin(),shortUrl.end());
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));