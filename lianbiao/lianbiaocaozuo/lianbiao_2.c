#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *q,*p,*t,*head;
int a,n;

void Creat_List();
void Last_Insert_List();
void Last_Delect_List();
void Delect_k_List();

void print();

int main()
{
    //printf("创建列表——输入列表长度：");
    Creat_List();
    print();

    //printf("末尾插入——输入插入的数：");
    Last_Insert_List();
    print();

    //printf("末尾删除");
    Last_Delect_List();
    print();

    //printf("第k节点插入——输入插入的数：");
    Delect_k_List();
    print();
}

void Creat_List()
{
    head = NULL;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a);
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a;
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
}

void Last_Insert_List()
{
    t = head;
    while(t!=NULL)
    {
        if(t->next == NULL)
        {
            scanf("%d", &a);
            p = (struct node *)malloc(sizeof(struct node));
            p->data = a;
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
            q = t->next->next;
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
    int k,count = 1;
    scanf("%d", &k);
    while(t!=NULL)
    {
        if(k == 1)
        {
            q = head;
            head = head->next;
            free(q);
            break;
        }
        if(count == k-1)
        {
            q = t->next;
            t->next = t->next->next;
            free(q);
            break;
        }
        t = t->next;
        count++;
    }
}

void print()
{
    t = head;
    while(t!=NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}