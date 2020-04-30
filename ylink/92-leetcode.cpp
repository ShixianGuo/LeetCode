class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        recursivelyReverse(head, 1, m, n);
        return head;
    }
    void recursivelyReverse(ListNode* cur, int depth, int reverse_begin, int cutoff)
    {
        if(depth > cutoff)
        {
            return;
        }
        else
        {
            v.push_back(cur->val);
            recursivelyReverse(cur->next, depth + 1, reverse_begin, cutoff);
            if(in(depth, reverse_begin, cutoff))
            {
                cur->val = v[cutoff - (depth + 1 - reverse_begin)];
            }
        }
    }
private:
    vector<int> v;
    bool in(const int val, const int lower, const int upper) 
    { return val >= lower && val <= upper; }
};
