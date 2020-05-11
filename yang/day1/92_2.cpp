class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        /*
        初始 pre 为第一个元素的前驱 即 pre->next = head;
        进入第一个while循环 退出时 pre是第m个元素的前驱 即preM————最后要指向n
        再走一步 pre是m  cur是m后继  记录m M————最后要指向n后继
        进入第二个while循环 保存 cur->next以确保不断链  变向（由pre->cur 变为 cur->pre）
        向后移动 退出循环 此时pre是n cur是n后继
        第m个元素 M指向cur即n后继
        第m个元素前驱 preM 指向n即pre
        如果给定m = 1 则返回头便是n  m!=1 返回即是原头head 
        */
        if(m == n || head == nullptr) return head;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* cur, * curNxt, * M, * preM;
        int count = 0;
        while(++count < m) pre = pre->next;//退出循环时 pre是m前驱 即preM
        preM = pre;
        pre = pre->next; //此时 pre 是m
        M = pre;//保存m的位置  最后指向n next
        cur = pre->next;//此时cur是m next
        while(count++ < n){// 退出循环时 pre是n
            curNxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = curNxt;
        }
        M->next = cur;
        preM->next = pre;
        return m==1 ? pre : head;
    }
};