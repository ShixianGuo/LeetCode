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
        int len1=0,len2=0;
        ListNode*ll1,*ll2;
        ll1=l1;
        ll2=l2;
        while(l1!=NULL)
        {
            len1++;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            len2++;
            l2=l2->next;
        }
        l1=ll1;
        l2=ll2;
        if(len1<len2)
        {
            swap(l1,l2);
            swap(len1,len2);
        }
        ll1=l1,ll2=l2;
        int add=0;
        while(len2--)
        {
            len1--;
            int a=l1->val;
            int b=l2->val;
            l1->val=(a+b+add)%10;
            //cout<<(a+b+add)%10<<endl;
            add=(a+b+add)/10;
            if(len2==0)break;
            l1=l1->next;
            l2=l2->next;
        }
        if(len1>0)
            l1=l1->next;
        while(len1--)
        {
            int a=l1->val;
            l1->val=(a+add)%10;
            add=(a+add)/10;
            if(len1==0)break;
            l1=l1->next;
        }
        if(add>0)
        {
            l1->next=new ListNode(add);
        }
        return ll1;
    }
};