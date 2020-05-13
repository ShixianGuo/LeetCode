13. 罗马数字转整数

罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3

示例 2:

输入: "IV"
输出: 4

示例 3:

输入: "IX"
输出: 9

示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.

示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.

--------------------------------------if-else模拟------------------


class Solution {
  public:
	  int romanToInt(string s) {
		  int len = s.length();
		  int ans = 0;
		  for (int i = 0; i < len; i++) {
			  if (s[i] == 'I') {
				  if (i + 1 < len&&s[i + 1] == 'V') {
					  ans = ans + 4;
					  i++;
				  }
				  else if (i + 1 < len&&s[i + 1] == 'X') {
					  ans = ans + 9;
					  i++;
				  }
				  else {
					  ans++;
				  }
			  }
			  else if (s[i] == 'X') {
				  if (i + 1 < len&&s[i + 1] == 'L') {
					  ans = ans + 40;
					  i++;
				  }
				  else if (i + 1 < len&&s[i + 1] == 'C') {
					  ans = ans + 90;
					  i++;
				  }
				  else {
					  ans = ans + 10;
				  }
			  }
			  else if (s[i] == 'C') {
				  if (i + 1 < len&&s[i + 1] == 'D') {
					  ans = ans + 400;
					  i++;
				  }
				  else if (i + 1 < len&&s[i + 1] == 'M') {
					  ans = ans + 900;
					  i++;
				  }
				  else {
					  ans = ans + 100;
				  }
			  }
			  else if (s[i] == 'V') {
				  ans = ans + 5;
			  }
			  else if (s[i] == 'L') {
				  ans = ans + 50;
			  }
			  else if (s[i] == 'D') {
				  ans = ans + 500;
			  }
			  else if (s[i] == 'M') {
				  ans = ans + 1000;
			  }
		  }
		  return ans;
	  }
  };

12. 整数转罗马数字

罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"

示例 2:

输入: 4
输出: "IV"

示例 3:

输入: 9
输出: "IX"

示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.

示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.



 class Solution {
  public:
	  string intToRoman(int num) {
		  map<int, string>mp;
		  string s = "";
		  mp[1000] = "M", mp[900] = "CM", mp[500] = "D";
		  mp[400] = "CD", mp[100] = "C", mp[90] = "XC";
		  mp[50] = "L", mp[40] = "XL", mp[10] = "X";
		  mp[9] = "IX", mp[5] = "V", mp[4] = "IV";
		  mp[1] = "I";
		  auto iter = mp.begin();
		  for (auto iter = mp.rbegin(); iter!=mp.rend() ; ) {
			  if (num / (iter->first) >= 1) {
				  int t = num / (iter->first);
				  while (t--) {
					  s = s + iter->second;
					  num = num - iter->first;
				  }
				  iter++;
			  }
			  else if (num < 4 && num != 0) {

				  s = s + "I";
				  num--;
			  }
			  else
				  iter++;

			  
		  }
		  return s;
	  }
  };



32. 最长有效括号

给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"

示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

--------------------------把所有匹配的括号标记为0，然后求最长的0序列---------
 class Solution {
  public:
	  int longestValidParentheses(string s) {
		  int len = s.length();
		  int ans = 0;
		  stack<int>p;
		  for (int i = 0; i < len; i++) {
			  if (s[i] == '(') {
				  p.push(i);
			  }
			  if (s[i] == ')' && !p.empty()) {
				  s[i] = '0';
				  s[p.top()] = '0';
				  p.pop();
			  }
		 }
		  int temp = 0;
		  for (int i = 0; i < len; i++) {
			  if (s[i] == '0') {
				  temp++;
			  }
			  else {
				  ans = max(ans, temp);
				  temp = 0;
			  }
		 }
		  ans = max(ans, temp);
		  return ans;
	  }
  };
