#include <stdio.h>
#include <malloc.h>
typedef  char elemtype;
typedef struct BiTNode
{
    elemtype data;                      
    struct BiTNode *lchild,*rchild;    
}BiTNode,*BiTree;


void CreateBinTree(BiTree *T);   /*这里省略以加入结点的先序序列输入,构造二叉链表的代码*/

void PreOrder(BiTree bt) ;

int main()
{
    BiTree bt;

    CreateBinTree(&bt);

    PreOrder(bt);

    return 0;
}

/* 请在这里填写答案 */
void PreOrder(BiTree bt) {
    if (bt == NULL) {
        return;
    }
    printf("%3d", bt->data);
    PreOrder(bt->lchild);
    PreOrder(bt->rchild);
}