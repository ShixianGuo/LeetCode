### 题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200430205829778.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzIzMzAxNzAz,size_16,color_FFFFFF,t_70)

### 思路
模板 伪代码
ret = dfs(ret->next);
ret->next->next = head;
head->next = NULL
return ret
### 代码

```cpp
class Solution {
public:
    ListNode* dfs(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *ret = dfs(head->next);
        //递归进行翻转
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *temp;
        temp = dfs(head);
        return temp;
    }
};
```

