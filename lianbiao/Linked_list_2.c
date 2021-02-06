/* 单向循环链表 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void Create(node **head, node **wear);                     //创建循环链表
void List_Insert_head(node *head);
void List_Insert_tail(node *head, node *wear);  
void List_Delect_k(node *head);
void List_Delect_key(node *head);
void List_Change_Data(node *head);
void List_Find_k(node *head);
void List_Find_key(node *head);
void print(node *head);
int Node_Number(node *head);    //计算链表结点的数量

int main()
{
    node *head, *wear;
    Create(&head, &wear);
    print(head);
    List_Insert_head(head);
    print(head);
    List_Insert_tail(head, wear);
    print(head);
    List_Delect_k(head);
    print(head);
    List_Delect_key(head);
    print(head);
    List_Change_Data(head);
    print(head);
    List_Find_k(head);
    List_Find_key(head);
}

void Create(node **head, node **wear)
{
    node *q,*p;
    *head = (node *)malloc(sizeof(node));
    (*head)->next = *head;
    q = *head;
    int b,n;
    scanf("%d", &n);
    if(n<=0)                        //规定输入的值的范围 >0
    {
        printf("FALSE");
        return;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d", &b);
        p = (node *)malloc(sizeof(node));
        p->data = b;
        p->next = *head;
        q->next = p;
        q = p;
        if(i == n-1)
        {
            *wear = p;              //设定尾指针
        }
    }
    return;
}

void List_Insert_head(node *head)
{
    node *p;
    int b;
    printf("Input the number you want to Insert in the LinkedList\'s head:");
    scanf("%d", &b);
    p = (node *)malloc(sizeof(node));
    p->data = b;
    p->next = head->next;
    head->next = p;

    return;
}

void List_Insert_tail(node *head, node *wear)
{
    node *p;
    int b;
    printf("Input the number you want to Insert in the LinkedList\'s tail:");
    scanf("%d", &b);
    p = (node *)malloc(sizeof(node));
    p->data = b;
    p->next = head;
    wear->next = p;

    return;
}

void List_Delect_k(node *head)
{
    node *q,*p;
    int k, count=1, number;
    p = head;
    printf("Input the sequence number of the LinkedList which you want to Delect:");
    scanf("%d", &k);
    number = Node_Number(head);
    if(k>number || k<=0)        //k的限定条件
    {
        printf("FALSE\n");
        return;
    }
    do
    {
        if(count == k)
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
            return;
        }
        count++;
        p = p->next;
    } while(p!=head);

    return;
}

void List_Delect_key(node *head)
{
    node *p,*q;
    int key, count=0;
    p = head;
    printf("Input the number of the LinkedList which you want to Delect:");
    scanf("%d", &key);
    do
    {
        if(p->next->data == key)
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
            count++;

            continue;               //continue表示如果删除了当前结点的下一个结点的话就不需要移动当前结点
        }
        p = p->next;
    } while(p!=head);
    if(count == 0)
    {
        printf("The LinkedList don't has number %d\n", key);
    }
    return;
}

void List_Change_Data(node *head)
{
    node *p;
    int k, count =1, b, number;
    p = head->next;
    printf("Input the sequence number of the LinkedList which you want to Change the data:");
    scanf("%d", &k);
    number = Node_Number(head);
    if(k>number || k<=0)
    {
        printf("FALSE\n");
        return;
    }
    do
    {
        if(count == k)
        {
            printf("Input the number which you want to have in the k\'th node:");
            scanf("%d", &b);
            p->data = b;
            return;
        }
        p = p->next;
        count++;
    } while (p!=head);
    
}

void List_Find_k(node *head)
{
    node *p;
    int k, count=1, number;
    p = head->next;
    printf("Input the sequence number of the LinkedList which you want to find:");
    scanf("%d", &k);
    number = Node_Number(head);
    if(k>number || k<=0)
    {
        printf("FALSE\n");
        return;
    }
    while(p!=head)
    {
        if(count == k)
        {
            printf("%d\n", p->data);
            return;
        }
        p = p->next;
        count++;
    }
}

void List_Find_key(node *head)
{
    node *p;
    int key, count=1, sum=0;        //count用来记录当前结点的序号，sum用来记录目前有几个符合key值的结点数据
    p = head->next;
    printf("Input the key which you want to Find in the LinkedList:");
    scanf("%d", &key);
    while(p!=head)
    {
        if(p->data == key)
        {
            printf("%d ", count);
            sum++;
        }
        p = p->next;
        count++;
    }
    if(sum == 0)
    {
        printf("Don\'t have key in the LinkedList");
    }
    printf("\n");
}

void print(node *head)
{
    node *t;
    t = head->next;
    while(t!=head)                  //循环链表的循环判断条件
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int Node_Number(node *head)
{
    node *p;
    int number=1;
    p = head->next;
    while(p->next!=head)
    {
        p = p->next;
        number++;
    }

    return number;
}
