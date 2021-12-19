#define MAXNODE  1024
#include <stdio.h>
#include <malloc.h>
typedef  char elemtype;
typedef struct BiTNode
{
    elemtype data;                     /*结点的数据域*/ 
    struct BiTNode *lchild,*rchild;    /*左右孩子指针*/
}BiTNode,*BiTree;

void InOrderOut(BiTree bt); /*这里省略了函数实现的代码*/

void CreateBinTree(BiTree *T);

int main()
{

     BiTree bt;
     CreateBinTree(&bt);

     InOrderOut(bt);

  return 0;

}

void CreateBinTree(BiTree *T)
{
    elemtype c;
    scanf("%c", &c);
    if (c == '0') {
        *T = NULL;
    } else {
        *T = (BiTree *)malloc(sizeof(BiTree));
        if (!T) {
            return;
        } else {
            (*T)->data = c;
            CreateBinTree(&(*T)->lchild);
            CreateBinTree(&(*T)->rchild);
        }
    }
}