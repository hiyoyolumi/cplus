#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

//这里的链表仅用于临时存储随机顾客到达时间(min)
//并对其进行排序，之后会被释放
typedef struct Lnode
{
    int data;   //min
    int identity; //客户身份 0 代表普通用户 1 代表vip用户
    struct Lnode *next;
}Lnode;

/**
 * @brief 链表的基本操作
 * 
 * @return Lnode* 返回链表头结点
 */
Lnode *Create();

/**
 * @brief 以下三个函数用于对数组进行排序
 * 
 * @param head 
 * @return Lnode* 
 */
Lnode* midnode(Lnode* head);
Lnode* mergelist(Lnode* left, Lnode* right);
Lnode* sortList(Lnode* head);

/**
 * @brief 打印链表
 * 
 * @param head 链表头结点
 */
void print(Lnode *head);

/**
 * @brief 销毁链表
 * 
 * @param head 链表头结点
 */
void link_destory(Lnode *head);

#endif