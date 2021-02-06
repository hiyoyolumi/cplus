#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* Create();
node* List_Insert_head(node *head);
void List_Insert_tail(node *head);
node* List_Delect_k(node *head);
node* List_Delect_key(node *head);
void List_Change_Data(node *head);
void List_Find_k(node *head);
void List_Find_key(node *head);
void print(node *head);

int main()
{
    node *head;
    head = Create();                //创建链表--无头结点
    print(head);
    head = List_Insert_head(head);  //头插
    print(head);                    
    List_Insert_tail(head);         //尾插
    print(head);
    head = List_Delect_k(head);     //删除第k个结点
    print(head);
    head = List_Delect_key(head);   //删除特定值的结点
    print(head);
    List_Change_Data(head);         //修改结点信息
    print(head);
    List_Find_k(head);              //查找第k个结点
    List_Find_key(head);            //查找特定值的结点序号
}

void List_Find_key(node *head)
{
    int key, count=1;
    printf("Input the key you want to find in the LinkedList:");
    scanf("%d", &key);
    printf("The key in the LinkedList\'s sequence number are:");
    while(head!=NULL)
    {
        if(head->data == key)
        {
            printf("%d ", count);
        }
        head = head->next;
        count++;
    }
    printf("\n");
}

void List_Find_k(node *head)
{
    int k, count=1;
    printf("Input the sequence number of the LinkedList\'s node which you want to find:");
    scanf("%d", &k);
    while(head!=NULL)
    {
        if(count == k)
        {
            printf("%d\n", head->data);
            break;
        }
        head = head->next;
        count++;
    }
}

void List_Change_Data(node *head)
{
    node *p,*q;
    int k,number, count=1;
    p = head;
    printf("Input the sequence number of the LinkedList\'s node which you want to change the data:");
    scanf("%d", &k);
    while(p!=NULL)
    {
        if(count == k)
        {
            printf("Input the number which you want to have in the k\'th node:");
            scanf("%d", &number);
            p->data = number;
            break;
        }
        p = p->next;
        count++;
    }
}

node* List_Delect_key(node *head)
{
    node *t,*q,*p,*head0;
    int key;
    head0 = (node *)malloc(sizeof(node));
    head0->next = head;             //加一个头结点--head0
    p = head;                       //定义两个指针
    q = head0;                      //p表示当前指针，q表示当前指针的前一个指针
    printf("Input the key in the LinkedList which you want to Delect:");
    scanf("%d", &key);
    while(p!=NULL)
    {
        if(p->data == key)
        {
            t = p;
            q->next = p->next;
            p = p->next;
            free(t);
            continue;               //continue表示如果p结点被删除后，q指针不需要移动
        }
        q = q->next;
        p = p->next;
    }
    return head0->next;
}

node* List_Delect_k(node *head)
{
    node *t,*q;
    int k, count=1;
    t = head;
    printf("Input the sequence number you want to Delect in the LinkedList:");
    scanf("%d", &k);
    while(t!=NULL)
    {
        if(k == 1)
        {
            q = head;
            head = head->next;
            free(q);
            return head;
        }
        if(count == k-1)
        {
            q = t->next;
            t->next = t->next->next;
            free(q);
            return head;
        }
        t = t->next;
        count++;
    }
    return head;
}

void List_Insert_tail(node *head)
{
    node *p;
    int b;
    printf("Input the number you want to Insert in the LinkedList\'s tail:");
    scanf("%d", &b);
    while(head!=NULL)
    {
        if(head->next == NULL)
        {
            p = (node *)malloc(sizeof(node));
            p->data = b;
            p->next = NULL;
            head->next = p;
            break;
        }
        head = head->next;
    }
}

node* List_Insert_head(node *head)
{
    node *p;
    int b;
    printf("Input the number you want to Insert in the LinkedList\'s head:");
    scanf("%d", &b);
    p = (node *)malloc(sizeof(node));
    p->data = b;
    p->next = head;
    head = p;
    return head;
}

node* Create()
{
    node *p,*q,*head;
    int n,b;
    head = NULL;
    printf("Input the amount of the LinkedList:");
    scanf("%d", &n);
    printf("Input the number of the LinkedList:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &b);
        p = (node *)malloc(sizeof(node));
        p->data = b;
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

void print(node *head)
{
    while(head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}