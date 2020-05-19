146. LRU缓存机制
要实现读取和存储的o(1)算法。
哈希链表
map：key-（key-value键值对在list中的位置）
list：key-value

665. 非递减数列
判断数列是否是一个非递减数列？ 看两个相邻元素的差即可
判断给出的数列是否仅仅改动一个元素，即可成为非递减数列？
    -找到第一个递减元素，将后一个元素赋给他，然后判断数列是否非递减
    -将他赋值给后一个元素，然后判断数列是否非递减
    -如果以上两步操作可以得到一个非递减数列，那就返回true 否则false
---------------------
开始跟着小组选题打卡
5.6 day 1
---------------------

1290. 二进制链表转整数
```C++
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res=0;
        while(head!=nullptr){
            res=res*2+head->val;
            head=head->next;
        }
        return res;
    }
};
```
--------------
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.6 MB, 在所有 C++ 提交中击败了100.00%的用户

468. 验证IP地址
```C++
class Solution {
public:
    vector<string> SplitString(const string& s, const string& c)
    {
        vector<string> v;
        string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
        return v;
    }

    bool checkStringIPV4(string s){
        int res=0;
        if(s.size()==0) return false;

        for(auto val:s){
            if('0'<=val && val<='9'){
                res=res*10+val-'0';
            }
            else{
                return false;
            }
            if(res>255){
                return false;
            }
            if(s[0]=='0'&& res!=0) return false;
            if(s.size()>1 && res==0) return false;

        }
        return true;
    }

    bool checkStringIPV6(string s){
        int res=0;
        if(s.size()>4||s.size()==0) return false;

        for(auto val:s){
            if('0'<=val && val<='9'){
                res=res*16+val-'0';
            }
            else if('A'<=val && val<='F'){
                res=res*16+val-'A';
            }
            else if('a'<=val && val<='f'){
                res=res*16+val-'a';
            }
            else{
                return false;
            }
        }
        return true;
    }


    string validIPAddress(string IP) {
        if(IP.size()==0) return "Neither";
        vector<string> res;

        if(IP.find('.')!=string::npos){
            if(IP.back()=='.') return "Neither";
            res=SplitString(IP, ".");
            if(res.size()!=4) return "Neither";

            for(auto val:res){
                cout<<val<<endl;
                if(!checkStringIPV4(val)) return "Neither";
            }
            return "IPv4";
        }
        else{
            if(IP.back()==':') return "Neither";
            res=SplitString(IP, ":");
            if(res.size()!=8) return "Neither";

            for(auto val:res){
                cout<<val<<endl;
                if(!checkStringIPV6(val)) return "Neither";
            }
            return "IPv6";;
        }
    }
    };
```
------------------------------------------------------------------------------------------------------------------------------
5.7 day 2

7.整数反转 逐位取值然后倒序输出

98. 验证二叉搜索树
中序遍历后看是否升序就好了
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void checkFunc(TreeNode* node,vector<int>& data){
        if(node==nullptr) return;

        if(node->left!=nullptr){
            checkFunc(node->left,data);
        }

        data.push_back(node->val);

        if(node->right!=nullptr){
            checkFunc(node->right,data);
        }
    }

    bool isValidBST(TreeNode* root) {
        vector<int>data;
        checkFunc(root,data);
        if(data.size()<=1) return true;
        for(int i=0;i<data.size()-1;i++){
            cout<<data[i]<<endl;
            if(data[i]>=data[i+1]){
                return false;
            }
        }
        return true;

    }
};
```
------------------------------------------------------------------------------------------------------------------------------
5.8 day 3

不用加法实现加法，异或得到非进位加法，与<<1得到进位。考察的是计算机基本原理
还有一个，减法的实现，其实是通过加法来完成的。

想一下相加顺序，要先入后出，那就是栈了
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> x;
        stack<int> y;
        while(l1!=nullptr){
            x.push(l1->val);
            l1=l1->next;
        }

        while(l2!=nullptr){
            y.push(l2->val);
            l2=l2->next;
        }
        ListNode* node=nullptr;
        int over=0;
        while(!x.empty()||!y.empty()||over>0){
            int sum=over;
            if(!x.empty()){
                sum+=x.top();
                x.pop();
            }
            if(!y.empty()||!y.empty()){
                sum+=y.top();
                y.pop();
            }
            ListNode* tmpnode=new ListNode(sum%10);
            tmpnode->next=node;
            node=tmpnode;
            over=sum/10;
        }
        return node;
    }
};
```
------------------------------------------------------------------------------------------------------------------------------
5.9 day 4
面试题42. 连续子数组的最大和 这个和股票的最大收益是一样的

面试题38. 字符串的排列
组合的题目，dfs，剪枝。在dfs之前对字符串进行排序。然后dfs中利用visited判断当前字母和上一个是否相同，如果相同，跳过。
函数外三个全局变量：
```C++
class Solution {
public:
    vector<string> res; //保存全部组合结果
    string tmp="";//中间单个组合的结果
    vector<bool> visited;//记录每个字母是否访问过
    int n;//记录一共有多少个可选字母
    void dfs(string s,int count){
        if(count==n){
            res.push_back(tmp);
            return;
        }
        else{
            for(int i=0;i<n;i++){
                //如果已经选到
                if(visited[i] ){
                    continue;
                }
                //（当前字母与上一个重复，并且上一个没有选过）
                if(i>0){
                    if( s[i]==s[i-1]&&!visited[i-1]){
                        continue;
                    }
                }
                tmp+=s[i];
                visited[i]=true;
                dfs(s,count+1);
                visited[i]=false;
                tmp.pop_back();
            }
        }

    }

    vector<string> permutation(string s) {
        if(s.empty()) return res;
        n=s.size();
        visited=vector<bool>(n,false);
        sort(s.begin(),s.end());
        dfs(s,0);
        return res;
    }
};
```

------------------------------------------------------------------------------------------------------------------------------
5.10 day 5

70. o爬楼梯，最简单的动态规划例子
8.atoi 好烦这个题目，可能正如评论所说的，细心也是一种能力

------------------------------------------------------------------------------------------------------------------------------
5.11 day 6

21. 合并两个有序链表：这个我之前做过了，当时通过了就没看题解，今天看下递归实现的答案，真的太简洁了，优雅～
    看完对递归和栈也有了进一步理解。
    148. 排序链表:同样是归并
------------------------------------------------------------------------------------------------------------------------------
5.12 day 7
13.罗马数字转整数
```C++
    class Solution {
    public:
        int romanToInt(string s) {
        map<char,int>translate{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
        };
        int res=0;
        for(int i=s.size()-1;i>0;i--){
            int val1=translate[s[i]];
            int val2=translate[s[i-1]];
            if(val1==5||val1==10){
                if(val2==1){
                    res+=val1-val2-val2;
                }
                else{
                    res+=val1;
                }
            }
            else if(val1==50||val1==100){
                if(val2==10){
                    res+=val1-val2-val2;
                }
                else{
                    res+=val1;
                }
            }
            else if(val1==500||val1==1000){
                if(val2==100){
                    res+=val1-val2-val2;
                }
                else{
                    res+=val1;
                }
            }
            else{
                res+=val1;
            }
        }
        res+=translate[s[0]];

        return res;
        }
    };
```
12. 整数转罗马数字
```C++
class Solution {
public:
    string intToRoman(int num) {
        map<int,string>translate{
            {1000,"M"},
            {900,"CM"},
            {500,"D"},
            {400,"CD"},
            {100,"C"},
            {90,"XC"},
            {50,"L"},
            {40,"XL"},
            {10,"X"},
            {9,"IX"},
            {5,"V"},
            {4,"IV"},
            {1,"I"},
        };
        string res="";
        while(num>0){
            for(auto rit=translate.rbegin();rit!=translate.rend();rit++) {
                auto val=*rit;
                // cout<<num<<" "<<val.first<<endl;
                if(num-val.first>=0){
                    res+=val.second;
                    num-=val.first;
                    break;
                }
            }
        }
        return res;
    }
};
```

----------------------------------------------------------
5.13 day 8
1360 求日期之间间隔
```C++
class Solution {
public:
    int _days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int daysBetweenDates(string date1, string date2) {
        return abs(getday(date1)-getday(date2));
    }

    int getday(string data){
        int year,month,day;
        sscanf(data.c_str(),"%d-%d-%d",&year,&month,&day);

        int res=0;
        for(int i=1971;i<year;i++){
            res+=365 + issleep(i);
        }
        for(auto i=1:month){
            if(i==2){
                res+=28+issleep(year);
            }
            else{
                res+=_days[i];
            }
        }
    }

    bool issleep(int year){
        return year % 4==0 && year%100!=0 ||year%400==0;
    }
};
```

面试题03 数组中重复数字
    将数组存入set中
面试题04 有序二维数组查找有无target
    左上角到右下角，可以认为是一个搜索树
面试题05 替换空格

面试题06. 从尾到头倒序打印链表
    用一个stack保存链表值

面试题09. 用两个栈实现队列
    
