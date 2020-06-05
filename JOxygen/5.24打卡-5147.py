class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        t =('i','o','u','a','e')
        if k == 0:
            return 0
        if k == 1:
            for c in s:
                if c in t:
                    return 1
            return 0
        
        tmp = 0
        for i in range(k):
            if s[i] in t:
                tmp+=1
        ans = tmp
        for i in range(k, len(s)):
            if s[i] in t :
                if s[i-k] not in t:
                    tmp += 1
                    ans = max(tmp,ans)
            else :
                if s[i-k] in t:
                    tmp -=1
        return ans