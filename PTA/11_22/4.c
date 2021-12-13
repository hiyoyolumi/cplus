#include <stdio.h>
#include <malloc.h>
typedef  char elemtype;
typedef struct BiTNode
{
    elemtype data;                      
    struct BiTNode *lchild,*rchild;    
}BiTNode,*BiTree;


void CreateBinTree(BiTree *T);   /*这里省略以加入结点的先序序列输入,构造二叉链表的代码*/

void LevelOrder(BiTree bt);

int main()
{
    BiTree bt;

    CreateBinTree(&bt);

    LevelOrder( bt);

    return 0;
}

void NRPreOrder(BiTree bt) {
    int top = 0;
    BiTree stack[100];
    
    while (bt != NULL || top > 0) {
        while (bt != NULL) {
            printf("%3c", bt->data);
            stack[top] = bt;
            top++;
            bt = bt->lchild;
        }
        top--;
        bt = stack[top];
        bt = bt->rchild;
    }
}

void NRPostOrder(BiTree bt) {
    if (bt == NULL) {
        return;
    }

    BiTree stack[1000];
    int top = 0;
    BiTNode *prev = NULL;

    while (bt != NULL || top > 0) {
        while (bt != NULL) {
            stack[top] = bt;
            top++;
            bt = bt->lchild;
        }
        top--;
        bt = stack[top];
        if (bt->rchild == NULL || bt->rchild == prev) {
            printf("%3c", bt->data);
            prev = bt;
            bt = NULL;
        } else {
            stack[top] = bt;
            top++;
            bt = bt->rchild;
        }
    }
}

/* 请在这里填写答案 */
void LevelOrder(BiTree bt) {
    if (bt == NULL) {
        return;
    }

    BiTree queue[100];
    int rear = 0;
    int front = 0;

    queue[rear] = bt;
    rear++;

    while (front < rear) {
        printf("%3c", queue[front]->data);
        
        if (queue[front]->lchild) {
            queue[rear] = queue[front]->lchild;
            rear++; //push
        }
        if (queue[front]->rchild) {
            queue[rear] = queue[front]->rchild;
            rear++; //push
        }
        front++; //pop
    }    
}