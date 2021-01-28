#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* Create();
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void print(struct ListNode *head);

int main()
{
    struct ListNode *l1,*l2,*sum;
    l1 = Create();
    l2 = Create();
    sum = addTwoNumbers(l1, l2);
    print(sum);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p,*q,*head;
    int a,b=0,c;
    head = NULL;
    while(l1 != NULL || l2 != NULL)
    {
        if(l1 != NULL && l2 != NULL)
        {
            c = l1->val + l2->val + b;
            a = c%10;       //余数
            p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = a;
            p->next = NULL;
            if(head == NULL)
            {
                head = p;
            }
            else
            {
                q->next = p;
            }
            q = p;
            b = c/10;       //多的数

            l1 = l1->next;  //指向数列的下两个数
            l2 = l2->next;
        }
        else if(l1 == NULL)
        {
            c = l2->val + b;
            a = c%10;       //余数
            p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = a;
            p->next = NULL;
            if(head == NULL)
            {
                head = p;
            }
            else
            {
                q->next = p;
            }
            q = p;
            b = c/10;       //多的数

            //l1 = l1->next;  //指向数列的下两个数
            l2 = l2->next;
        }
        else if(l2 == NULL)
        {
            c = l1->val + b;
            a = c%10;       //余数
            p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = a;
            p->next = NULL;
            if(head == NULL)
            {
                head = p;
            }
            else
            {
                q->next = p;
            }
            q = p;
            b = c/10;       //多的数

            l1 = l1->next;  //指向数列的下两个数
            //l2 = l2->next;
        }
    }
    if(b == 0)
    {
        return head;
    }
    else
    {
        p =(struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = b;
        p->next = NULL;
        q->next = p;

        return head;
    }
}

struct ListNode* Create()
{
    struct ListNode *p,*q,*head;
    int n,b;
    head = NULL;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &b);
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = b;
        p->next = NULL;
        if(head == NULL)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    return head;
}

void print(struct ListNode *head)
{
    while(head!=NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    return;
}