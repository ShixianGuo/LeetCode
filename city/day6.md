输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

class Solution {
public:
     int  NumberOf1(int n) {
         bitset<32> tw(n);
             return tw.count();
         
     }
};


给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=NULL)
        {
            ans=ans*2+head->val;
            head=head->next;
        }
        return ans;

    }
};


468. 验证IP地址

编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址。

IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；

同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。

IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。

然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。

同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。

说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。

class Solution {
public:
	string validIPAddress(string IP) {
		int len = IP.length();
		if(len>=40)
			return "Neither";
		int vis = 0;
		for (int i = 0; i < len; i++)
		{
			if (IP[i] == '.')
			{
				vis = 1;
				break;
			}
		}
		len = len + 2;
		if (vis==1)
		{
			string s = ".";
			s = s + IP;
			s = s + '.';
			int flag = 0;
			for (int i = 0; i < len; i++)
			{
				if (s[i] == '.')
				{
					if(s[i+1]=='.')
						return "Neither";
					flag++;
					int t = 0;
					if (s[i + 1] == '0'&&s[i+2]!='.')
						return "Neither";
					
					while (s[i + 1] != '.'&&i < len-1)
					{
						i++;
						if(s[i]<'0'||s[i]>'9')
							return "Neither";
						t = t * 10 + (s[i] - '0');
					}
					if (t < 0 || t>255)
						return "Neither";
				}
			}
			if (flag == 5)
				return "IPv4";
			else
				return "Neither";
		}
		else
		{
			string s = ":";
			s = s + IP;
			s = s + ':';
			int t, flag = 0;
			//统一转换成小写
			for (int i = 0; i < len; i++)
			{
				if ('A' <= s[i] && s[i] <= 'Z')
				{
					char c = s[i] + 32;
					s[i] = c;
				}
			}
			for (int i = 0; i < len; i++)
			{
				if (s[i] == ':'&&s[i + 1] == ':')
					return "Neither";
				if (s[i] == ':')
				{
					flag++;
					t = 0;
					while (s[i + 1] != ':'&&i < len-1&&t <= 4)
					{
						i++;
						if ('a' <= s[i] && s[i] <= 'f')
							t++;
						else if ('0' <= s[i] && s[i] <= '9')
							t++;
						else
						{
							return "Neither";
						}
					}
					if(t>4)
						return "Neither";
				}
			}
			if (flag == 9)
				return "IPv6";
			else
				return "Neither";
		}

	}
};

给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

    字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
    每个元音 'a' 后面都只能跟着 'e'
    每个元音 'e' 后面只能跟着 'a' 或者是 'i'
    每个元音 'i' 后面 不能 再跟着另一个 'i'
    每个元音 'o' 后面只能跟着 'i' 或者是 'u'
    每个元音 'u' 后面只能跟着 'a'

由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-vowels-permutation



class Solution {
public:
	typedef long long ll;
	const ll mod = 1000000007;
	struct mat//定义矩阵结构体
	{
		ll m[5][5];
		mat()
		{
			memset(m, 0, sizeof(m));
		}
	};
	mat mul(mat &A, mat &B)
	{
		mat C;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					C.m[i][j] = (C.m[i][j] + A.m[i][k] * B.m[k][j]) % mod;
				}
			}
		}
		return C;
	}
	mat pow(mat A, ll n)
	{
		mat B;
		for (int i = 0; i < 5; i++)//初始化方阵
			B.m[i][i] = 0;

		//初始被乘矩阵的初值
		B.m[0][0] = 1;
		B.m[1][0] = 1;
		B.m[2][0] = 1;
		B.m[3][0] = 1;
		B.m[4][0] = 1;

		while (n)
		{
			if (n & 1)
				B = mul(A, B);//注意这里，矩阵的左乘和右乘是不一样的，对应的系数矩阵也不一样
			A = mul(A, A);
			n >>= 1;
		}
		return B;
	}
	int countVowelPermutation(int n) 
    {
		mat A;//矩阵A是系数矩阵（转移矩阵）
		A.m[0][1] = 1;
		A.m[1][0] = 1, A.m[1][2] = 1;
		A.m[2][0] = 1, A.m[2][1] = 1, A.m[2][3] = 1, A.m[2][4] = 1;
		A.m[3][2] = 1, A.m[3][4] = 1;
		A.m[4][0] = 1;


		if (n == 1)
		{
			return 5;
		}
		else
		{
			mat B = pow(A, n - 1);
			ll ans = B.m[0][0] + B.m[1][0] + B.m[2][0] + B.m[3][0] + B.m[4][0];
            int temp=ans % mod;
			return temp;
		}
	}

};