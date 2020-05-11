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
------------------------------------------------------------------------------------------------------------------------------
开始跟着小组选题打卡
5.6 day 1
------------------------------------------------------------------------------------------------------------------------------

1290. 二进制链表转整数
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
------------------------------------------------------------------------------------------------------------------------------
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.6 MB, 在所有 C++ 提交中击败了100.00%的用户

468. 验证IP地址


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
------------------------------------------------------------------------------------------------------------------------------
5.7 day 2

7.整数反转 逐位取值然后倒序输出

98. 验证二叉搜索树
中序遍历后看是否升序就好了
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
------------------------------------------------------------------------------------------------------------------------------
5.8 day 3

不用加法实现加法，异或得到非进位加法，与<<1得到进位。考察的是计算机基本原理
还有一个，减法的实现，其实是通过加法来完成的。

想一下相加顺序，要先入后出，那就是栈了

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
------------------------------------------------------------------------------------------------------------------------------
5.9 day 4
面试题42. 连续子数组的最大和 这个和股票的最大收益是一样的

面试题38. 字符串的排列 
组合的题目，dfs，剪枝。在dfs之前对字符串进行排序。然后dfs中利用visited判断当前字母和上一个是否相同，如果相同，跳过。
函数外三个全局变量：
vector<string> res; //保存全部组合结果
string tmp=""; //中间单个组合的结果
int n;//记录一共有多少个可选字母
vector<bool> visited;//记录每个字母是否访问过


class Solution {
public:
    vector<string> res;
    string tmp="";
    vector<bool> visited;
    int n;
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


------------------------------------------------------------------------------------------------------------------------------
5.10 day 5

70. o爬楼梯，最简单的动态规划例子
8.atoi 好烦这个题目，可能正如评论所说的，细心也是一种能力

------------------------------------------------------------------------------------------------------------------------------
5.11 day 6

21. 合并两个有序链表：这个我之前做过了，当时通过了就没看题解，今天看下递归实现的答案，真的太简洁了，优雅～
    看完对递归和栈也有了进一步理解。
    148. 排序链表:同样是归并
    
