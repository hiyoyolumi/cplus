#ifndef __HEAD_H
#define __HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

//定义布尔变量
#define TRUE 1
#define FALSE 0

#define WINDOW_NUMS 4 //银行窗口数量

//24小时制时间结构体
typedef struct Time {
    int min_h;
    int min_min;
}Time;

//队列结构体
typedef struct Node {
    int serial_num;     //客户编号

    Time arrivd_time;    //到达时间
    int wait_time;      //等待时间
    Time leave_time;     //离开时间
    int business_time;  //办理业务时间
    Time star_time;      //开始办理时间
    struct Node *next;
} Time_data;

typedef struct Queue {
    Time_data *front;
    Time_data *rear;
} Queue;

/**
 * 函数声明
 */

//qsort()辅助函数
int cmpfunc (const void * a, const void * b);

/**
 * 队列
 */

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

//得到队列中的结点数量
//参数：队列
//返回值：结点数量
int get_Queue_num(Queue *q);

/**
 * 欢迎函数
 */

//银行欢迎界面
void welcome();  //OK

//银行菜单界面
void menu();    //OK

//结束界面
void good_bye();

//初始化随机顾客
void init_custom(Queue *q);

//进入银行
//主函数的入口
//无返回值
void Step_in();

//生成随机数
//返回随机数
int get_rand_num(); //OK

//根据随机数生成时间
//返回 Time 结构体
Time get_rand_time();

//将分钟数转换成 24进制 时间
Time turn_to_time(int min);

/**
 * @brief Get the leave time object
 * 
 * @param arrived_time 
 * @return Time 
 */
Time get_leave_time(Time arrived_time);

//取号
//返回当前编号
//现在看起来没有用
int get_serial_num(Queue *q);   //OK

#endif