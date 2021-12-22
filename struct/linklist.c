#include "linklist.h"
#include "HEAD.h"

/**
 * @brief Create()函数中生成随机数存入链表中
 * 
 * @return Lnode* 
 */
Lnode *Create() {
    Lnode *p, *q, *head;
    head = (Lnode *)malloc(sizeof(Lnode));
    head->data = -1;
    head->next = NULL;
    q = head;
    printf("---输入顾客的数量:");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int b = get_rand_num();
        p = (Lnode *)malloc(sizeof(Lnode));
        p->data = b;
        p->next = NULL;
        
        q->next = p;
        q = p;
    }
    return head;
}

void print(Lnode *head)
{
    head = head->next;
    while(head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


/**
 * @brief 以下三个函数用于对数组进行排序
 * 
 * @param head 
 * @return Lnode* 
 */
Lnode* midnode(Lnode* head)
{
    if(!head || !head->next)
    {
        return head;
    }
    Lnode *p,*q;
    p = head->next;
    q = head;
    while(p->next && p->next->next)
    {
        p = p->next->next;
        q = q->next;
    }
    return q;
}

Lnode* mergelist(Lnode* left, Lnode* right)
{
    if(!left)
    {
        return right;
    }
    else if(!right)
    {
        return left;
    }
    else if(left->data < right->data)
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

Lnode* sortList(Lnode* head){
    if(!head || !head->next)
    {
        return head;
    }
    Lnode *left,*right,*mid,*righthead,*newhead;
    mid = midnode(head);
    righthead = mid->next; 
    mid->next = NULL;

    left = sortList(head);
    right = sortList(righthead);

    newhead = mergelist(left,right);
    return newhead;
}

void link_destory(Lnode *head) {
    Lnode *p, *q;
    p = head->next;
    while (p) {
        q = p;
        p = p->next;
        free(q);
        q = NULL;
    }
    free(head);
    head = NULL;
}