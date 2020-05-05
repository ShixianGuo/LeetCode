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
        string s1, s2;
        ListNode* current = l1;
        while(current)
        {
            s1 += (current->val + 48);
            current = current->next;
        }
        current = l2;
        while(current)
        {
            s2 += (current->val + 48);
            current = current->next;
        }
        string res_s = addBig(s1.size() > s2.size() ? s1 : s2, s1.size() > s2.size() ? s2 : s1);
        ListNode* new_list = new ListNode(INT_MIN);
        current = new_list;
        int i = 0;
        while(i < res_s.size())
        {
            ListNode* pnew = new ListNode(res_s[i] - 48);
            current->next = pnew;
            current = current->next;
            i++;
        }
        return new_list->next;
    }
    string addBig(string& s1, string& s2)  //assume s1 is longer
    {
        string res;
        char modify[2] = {'0', '\0'};
        int index;
        bool carry = false;
        while(s2.size() < s1.size())
            s2 += '0';
        for(index = 0; index < s1.size(); index++)
        {
            modify[0] = (s1[index] + s2[index] - 96) % 10 + 48;
            if(carry)
            {
                modify[0] += 1;
                if(modify[0] > '9')
                {
                    modify[0] = '0';
                    carry = true;
                    goto plus;
                }
            }
            else
            {
                ;
            }
            if(s1[index] + s2[index] - 96 >= 10)
            {
                carry = true;
            }
            else
            {
                carry = false;
            }
            plus:res += modify;
        }
        if(carry && index == s1.size())
        {
            modify[0] = '1';
            res += modify;
        }
        return res;
    }
};
