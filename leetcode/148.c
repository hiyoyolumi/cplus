给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 

示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]

示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

示例 3：
输入：head = []
输出：[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//既然是排序，我一开始想到的方法就是这个
//选择排序的思路
//但是
//有一个很长的测试用例
//使用这种方法会超时
//然后就想用快排的思路来搞
//但是应用到链表上有点麻烦

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *t,*p,*q;
    int duff;
    t = head;
    while(t)
    {
        duff = t->val;
        p = t->next;
        q = t;
        while(p)
        {
            if(p->val < duff)
            {
                duff = p->val;
                q = p;
            }
            p = p->next;
        }
        if(q == t)
        {
            t = t->next;
            continue;
        }
        q->val = t->val;
        t->val = duff;
        t = t->next;
    }
    return head;
}
