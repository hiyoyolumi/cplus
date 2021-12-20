#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//定义布尔变量
#define TRUE 1
#define FALSE 0

#define WINDOW_NUMS 4 //银行窗口数量

//队列结构体
typedef struct Node {
    int arrivd_time;    //到达时间
    int wait_time;      //等待时间
    int leave_time;     //离开时间
    int business_time;  //办理业务时间
    int star_time;      //开始办理时间
    struct Node *next;
} Time_data;

struct Queue {
    Time_data *front;
    Time_data *rear;
};

/**
 * 函数声明
 **/

// 打印欢迎界面
void welcome();  //OK

//队列初始化
//无参数
//返回 Queue * 结点
Queue *initQueue(); //OK

//判断队列空
//参数：队列
//返回 1 为空，0 为非空
int isEmpty(Queue *q);  //OK

//入队
//参数：队列，结点
//无返回值
void Enqueue(Queue *q, Time_data *data);    //OK

//出队
//参数：队列
//返回 1 成功， 0 失败
int Out_Queue(Queue *q);  //OK

#endif