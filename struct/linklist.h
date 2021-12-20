#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

//这里的链表仅用于临时存储随机顾客到达时间(min)
//并对其进行排序，之后会被释放
typedef struct Lnode
{
    int data;   //min
    struct Lnode *next;
}Lnode;

/**
 * @brief 链表的基本操作
 * 
 * @return Lnode* 
 */
Lnode *Create();
Lnode* midnode(Lnode* head);
Lnode* mergelist(Lnode* left, Lnode* right);
Lnode* sortList(Lnode* head);
void print(Lnode *head);

#endif