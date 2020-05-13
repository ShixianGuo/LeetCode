class Solution {
public:
	vector<string> res;

	bool isValid(const string& tmp)
	{
		if (tmp[0] == '0' && tmp.size() > 1)  
            return false;

		int num = stoi(tmp);
		if (0 <= num && num <= 255) 
            return true;
		else
            return false;
	}

	void dfs(string& s, int depth, vector<string>& tmp)
	{
		if (depth == 4 && s.size() != 0)
            return;
		if (depth == 4 && s.size() == 0)
		{
			string a;
			for (int i = 0; i < 4; ++i)
			{
				a += i != 3 ? tmp[i] + "." : tmp[i];
			}
			res.push_back(a);
			return;
		}
		if (s.size() < 4 - depth || s.size() > 12 - 3 * depth)
            return;

		for (int i = 1; i <= 3; ++i)
		{
			if (i > s.size())
                continue;
			string subStr = s.substr(0, i);
			if (isValid(subStr))
			{
				tmp.push_back(subStr);
				string leftStr = s.substr(i);

				dfs(leftStr, depth + 1, tmp);
				tmp.pop_back();
			}
		}
	}
public:
	vector<string> restoreIpAddresses(string s)
	{
		if (s.size() < 4 || s.size() > 12)
            return {};

		vector<string> tmp;
		dfs(s, 0, tmp);

		return res;
	}
};