class Solution {
public:
    string toGoatLatin(string S) {
        char c[]={'a','e','i','o','u','A','E','I','O','U'};
        istringstream iss(S);
        vector<string> v((istream_iterator<string>(iss)),istream_iterator<string>());
        // copy(v.begin(),v.end(),ostream_iterator<string>(cout,"\n"));
        for(int i=0;i<v.size();++i){
            bool flag=0;
            for(int j=0;j<10;++j){
                if(v[i][0]==c[j]){
                    v[i]+="ma";
                    flag=1;
                    break;
                }
            }
            if(!flag){
                char tmp=v[i][0];
                v[i].erase(0,1);
                v[i]+=tmp;       //左边的加号表示字符串拼接，右边表示正常的加号
                v[i]+="ma";   //char和string不能连在一起加
            }
            for(int j=0;j<=i;++j) v[i].push_back('a');
        }
        string ans;
        for(int i=0;i<v.size()-1;++i) ans+=v[i]+' ';
        ans+=v[v.size()-1];
        return ans;
    }
};