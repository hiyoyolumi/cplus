请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//这个题目使用双指针的思路
//先使用快慢指针，找到链表的中间结点
//然后逆置后半部分的链表
//将两个链表进行比对得出结果

bool isPalindrome(struct ListNode* head){
    struct ListNode *fast,*slow,*p,*q,*r,*t;
    fast = head;
    slow = head;
    while(fast && slow && slow->next && fast->next && fast->next->next)	//找到中间结点
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast && slow)			//如果是奇数的话，那么中间结点归前半段
    {
        p = slow->next;
        r = NULL;
    }
    else				//如果链表不存在的话，返回true
    {
        return true;
    }
    while(p)
    {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    t = head;
    while(r && t)
    {
        if(t->val != r->val)
        {
            return false;
        }
        r = r->next;
        t = t->next;
    }
    return true;
}
