给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 

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

//归并排序基于分治算法。最容易想到的实现方式是自顶向下的递归实现，考虑到递归调用的栈空间，
//自顶向下归并排序的空间复杂度是 O(\log n)O(logn)。
//如果要达到 O(1)O(1) 的空间复杂度，则需要使用自底向上的实现方式。

struct ListNode* midnode(struct ListNode* head)     //找链表中点     快慢指针
{
    if(!head || !head->next)
    {
        return head;
    }
    struct ListNode *p,*q;
    p = head->next;
    q = head;
    while(p->next && p->next->next)
    {
        p = p->next->next;
        q = q->next;
    }
    return q;
}

struct ListNode* mergelist(struct ListNode* left, struct ListNode* right)   //21.合并两个有序链表
{
    if(!left)
    {
        return right;
    }
    else if(!right)
    {
        return left;
    }
    else if(left->val < right->val)
    {
        left->next = mergelist(left->next, right);
        return left;
    }
    else
    {
        right->next = mergelist(left, right->next);
        return right;
    }
}

struct ListNode* sortList(struct ListNode* head){       
    if(!head || !head->next)
    {
        return head;
    }
    struct ListNode *left,*right,*mid,*righthead,*newhead;
    mid = midnode(head);
    righthead = mid->next; 
    mid->next = NULL;       //从中间分开

    left = sortList(head);              //递归
    right = sortList(righthead);        //最终成为一个一个的单结点

    newhead = mergelist(left,right);    //然后有序合并
    return newhead;
}