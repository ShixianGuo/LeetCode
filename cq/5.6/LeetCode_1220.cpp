class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod=1e9+7;
        int a,e,i,o,u;
        a=e=i=o=u=1;
        for(int j=1;j<n;++j){
            int aa,ee,ii,oo,uu;
            aa = ((e + i) % mod + u) % mod;
            ee = (a + i) % mod;
            ii = (e + o) % mod;
            oo = i;
            uu = (i + o) % mod;
            a = aa, e = ee, i = ii, o = oo, u = uu;
        }
        return ((long long) a + e + i + o + u) % mod;
    }
};