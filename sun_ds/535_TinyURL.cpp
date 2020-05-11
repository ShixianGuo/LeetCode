// @File   : 535_TinyURL.cpp
// @Source : https://leetcode-cn.com/problems/encode-and-decode-tinyurl/
// @Title  : 535. TinyURL 的加密与解密
// @Auther : sun_ds
// @Date   : 2020/5/3

/**  题目描述：
    TinyURL是一种URL简化服务， 比如：当你输入一个URL https://leetcode.com/problems/design-tinyurl 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk.

    要求：设计一个 TinyURL 的加密 encode 和解密 decode 的方法。你的加密和解密算法如何设计和运作是没有限制的，你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/encode-and-decode-tinyurl
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 加密解密。核心，为每个网址创建一个唯一的key，返回key作为短链接，真正的网址存储在map结构中。
 * 使用62进制存储key，其中可以由随机数随机生成。
 * 为了保证key足够短，并规范化，固定key长度为6位。
 *
 * 那么key可以表示的范围为 62^6 个。
 *
 *
 */



class Solution {
public:
    //加密解密，核心是生成加密的key和真正网址的对应
    unordered_map<string,string> m;
    //使用62进制作为key的表示
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //固定key的长度为6，随机生成
    //短链接
    string getKey(){
        string key(6,' ');
        for(int i=0;i<6;i++){
            key[i] = alphabet[rand()%62];
        }
        return key;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key;
        //防止有重复的key
        do{
            key = getKey();
        }while(m.count(key));
        m[key]=longUrl;
        return "https://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        //获取key
        string key = shortUrl.substr(20);
        //根据key从map中获取真正网址
        return m[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

