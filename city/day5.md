输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int>p;
		vector<int>tp;
		while (head != NULL)
		{
			tp.push_back(head->val);
			head = head->next;
		}
		for (int i = tp.size() - 1; i >= 0; i--)
		{
			p.push_back(tp[i]);
		}
		return p;
	}
};


一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

换种想法，考虑每个台阶的模板在不在，每个台阶有2种情况，最后一块台阶一定在
class Solution {
public:
    
    int jumpFloorII(int number) {
       if(number==0)
        return 0;
    else
        return pow(2,number-1);

    }

};

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？ 

数学归纳法分析：先列举前几项，在找规律：用n个m*1的小矩形去覆盖一个n*m的大矩形一共有f[n-1]+f[n-m]种方法
class Solution {
public:
    int rectCover(int number) {
        if (number <= 0) {
            return number;
        }
        int f1 = 1;
        int f2 = 2;
        int f3;
         
        for (int i = 3; i <= number; i++) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};