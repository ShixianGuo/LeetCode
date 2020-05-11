lt21.合并两个有序链表
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if(l1==nullptr)
            return l2;
        if (l2==nullptr)
           return l1;
       ListNode *head=nullptr;
        if(l1->val>l2->val)
          {
            head=l2;
            head->next=mergeTwoLists(l2->next,l1);
          }
          else
            {
                head=l1;
                head->next=mergeTwoLists(l1->next,l2);
            }
       return head;
    }
 题解：递归实现，判断当前l1与l2的值大小，将小值作为head，并继续求head->next(小值->next,max);
lt148.排序链表
ListNode* sortList(ListNode* head) {
        auto dummy=new ListNode(-1);
        dummy->next=head;
        int len=0;
        for(auto p=head;p;p=p->next) len++;
        for(int i=1;i<len;i*=2)
         {
            auto cur=dummy;
            for(int j=0;j+i<len;j+=i*2)
              {
               auto left=cur->next;
               auto right=cur->next;
               for(int k=0;k<i;k++) right=right->next; 
               int l=0,r=0;
               while(l<i&&r<i&&right)
                {
                  if(left->val<right->val)
                   {
                       cur->next=left;
                       left=left->next;
                       cur=cur->next;
                       l++;
                   }    
                   else
                   {
                       cur->next=right;
                       right=right->next;
                       cur=cur->next;
                       r++;
                   }
                } 
                while(l<i)
                {
                    cur->next=left;
                    left=left->next;
                    cur=cur->next;
                    l++;
                }
                while(r<i&&right)
                {
                   cur->next=right;
                   right=right->next;
                   cur=cur->next;
                   r++;
                 }
                cur->next=right;       
              }
         }
         return dummy->next;
    }
 题解：两两归并，依次扩展。
lt25.k个一组翻转链表
 ListNode* reverseKGroup(ListNode* head, int k) {
      int len=0;
      ListNode *dummy=new ListNode(-1);
      dummy->next=head;
      for(auto p=head;p;p=p->next) len++;
      auto pre=dummy;
      for(int j=0;j+k<=len;j+=k)
        {   
           auto s=pre->next;
           auto p=pre->next;
           auto q=pre->next->next;
           for(int i=0;i<k-1;i++)
           {
              auto next=q->next;
              q->next=p;
              p=q;
              q=next;
           }
           pre->next=p;
           s->next=q;
           pre=s;
        }
        return dummy->next;
    }
 题解：记录翻转前节点，翻转第一个节点，翻转完k个后调整相应指针，中间为链表反转的常规写法。
 
今天其他学习情况：观看leetcode二叉树专题，明天整理出来。
 
