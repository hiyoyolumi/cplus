#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int n,b;
struct node *p,*q,*t,*a,*head;

void Create_List();
void Last_Insert_List();
void Last_Delect_List();
void Delect_k_List();
void print();

int main()
{
    Create_List();
    print();
    Last_Insert_List();
    print();
    Last_Delect_List();
    print();
    Delect_k_List();
    print();
}

void Create_List()
{
    head = NULL;
    a = (struct node *)malloc(sizeof(struct node));
    a->data = 1;
    a->next = NULL;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &b);
        p = (struct node *)malloc(sizeof(struct node));
        p->data = b;
        p->next = NULL;
        if(head == NULL)
        {
            a->next = p;
            head = a;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
}

void Last_Insert_List()
{
    t = head;
    while(t!=NULL)
    {
        if(t->next == NULL)
        {
            scanf("%d", &b);
            p = (struct node *)malloc(sizeof(struct node));
            p->data = b;
            p->next = NULL;
            t->next = p;
            break;
        }
        t = t->next;
    }
}

void Last_Delect_List()
{
    t = head;
    while(t!=NULL)
    {
        if(t->next->next == NULL)
        {
            q = (struct node *)malloc(sizeof(struct node));
            q = t->next;
            t->next = NULL;
            free(q);
            break;
        }
        t = t->next;
    }
}

void Delect_k_List()
{
    t = head;
    int k;
    int count = 1;
    scanf("%d", &k);
    while(t!=NULL)
    {
        if(count == k)
        {
            q = t->next;
            t->next = t->next->next;
            free(q);
            break;
        }
        count++;
        t = t->next;
    }
}

void print()
{
    int num = 0;
    t = head;
    while(t!=NULL)
    {
        if(!num)
        {
            num++;
            t = t->next;
        }
        else
        {
            printf("%d ", t->data);
            t = t->next;
        }
    }
    printf("\n");
}