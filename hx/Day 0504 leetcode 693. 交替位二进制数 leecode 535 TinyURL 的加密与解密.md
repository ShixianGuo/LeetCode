![在这里插入图片描述](https://img-blog.csdnimg.cn/20200504234233949.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzIzMzAxNzAz,size_16,color_FFFFFF,t_70)
### 思路
移位解决 当然有O(1) 解法 (n>>1) ^ n 判断结果是否全1 
### 代码

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre=n&1;
        n = n >> 1;
        int cur=0;
        while(n)
        {
            cur = n&1;
            if(pre==cur)
                return false;
            n = n >> 1;
            pre = cur;
        }
        return true;
    }
};
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200504235112409.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzIzMzAxNzAz,size_16,color_FFFFFF,t_70)
### 思路 
凯撒对称加密
### 代码

```cpp
class Solution {
public:
    int Caesar=3;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string str=longUrl;
        for(int i=0;i<str.length();++i)
            str[i]+=Caesar;
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string str=shortUrl;
        for(int i=0;i<str.length();++i)
            str[i]-=Caesar;
        return str;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```

