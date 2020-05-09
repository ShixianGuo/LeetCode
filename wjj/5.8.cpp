面试题17.01 不用加号的加法
class Solution {
public:
    int add(int a, int b) {
      int sum=0;
      int i=0;
      while(b)
      {
          sum=a^b;
          i=((unsigned int)a&b)<<1;
          a=sum;
          b=i;
      }
      return a; 
    }
};
题解：不可以使用运算符号实现加法，可以利用位运算完成。异或相当于无进位加法，然后使用&运算得到需要进位的位置，并且进行左移，循环累加无进位加法结果与进位位置结果，
直至进位结果为零。


leetcode 445两数相加||
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     stack<int>s1;
     stack<int>s2;
     int sum=0;
     int p=0;
     while(l1!=nullptr)
       {
           s1.push(l1->val);
           l1=l1->next;
       }
     while(l2!=nullptr)
       {
         s2.push(l2->val);
         l2=l2->next;
       }
       ListNode *head=new ListNode(-1);
      while(!s1.empty()||!s2.empty()||p)
         { sum=p;
           sum+=s1.empty()?0:s1.top();
           sum+=s2.empty()?0:s2.top();
           if(!s1.empty()) s1.pop();
           if(!s2.empty()) s2.pop();
           p=sum/10;
           sum%=10;
           ListNode *node=new ListNode(sum);
           node->next=head->next;
           head->next=node;
         } 
        return head->next;
    }
};
题解：第一眼看到，题目要求不能逆序链表于是想到利用栈实现逆序，遍历两个链表分别入栈，然后弹栈实现加法，记录进位。使用了哑结点进行头插法建立链表。
