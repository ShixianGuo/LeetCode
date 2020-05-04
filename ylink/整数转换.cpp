class Solution
{
public:
	int convertInteger(int a, int b) 
	{
		int diff = a ^ b;
		return find1count(diff);
	}
	int find1count(const int a)
	{
		int count = 0;
		while(a)
		{
			a = a & (a - 1);
			count++;
		}
		return count;
	}
}
