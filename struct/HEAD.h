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

#define WINDOW_NUMS 4  //银行窗口数量

// 24小时制时间结构体
typedef struct Time {
    int min_h;
    int min_min;
} Time;

//窗口结构体
//status 表示窗口的状态 即 是否空闲 1 占用 0 为空闲
//cur_custom_serial 表示当前服务的客户编号
//cur_leave_time 表示当前客户的离开时间
typedef struct Window_status {
    int status;
    int cur_custom_serial;
    Time cur_leave_time;
} Window_status;

//队列结构体
typedef struct Node {
    int serial_num;     //客户编号
    int window_serial;  //办理业务的窗口
    int vip_status;     // 1 为VIP，0 为普通用户

    Time arrivd_time;   //到达时间
    int wait_time;      //等待时间 要不要的吧
    Time leave_time;    //离开时间
    int business_time;  //办理业务时间 固定为 10 ，后续完善的话可以将其改为随机数(1~30)
    Time star_time;     //开始办理时间
    struct Node *next;
} Time_data;

typedef struct Queue {
    Time_data *head;  //存放队列头结点

    Time_data *front;
    Time_data *rear;
} Queue;

/**
 * 函数声明
 */


/**
 * @brief 判断当前是否有空闲窗口
 * 
 * @return int 有空闲窗口 返回窗口号
 *         如果没有窗口则返回 -1
 */
int get_free_window();

/**
 * @brief 找到最早结束的窗口
 * 
 * @return int 返回最早结束的窗口编号 
 */
int find_fast_window();

/**
 * @brief 由结点的开始时间(star_time)得到离开时间(leave_time)
 * 
 * @param node 
 * @return Time 
 */
void star_to_leave(Time_data *node);    //OK

// qsort()辅助函数
int cmpfunc(const void *a, const void *b);

/**
 * 队列
 */

//队列初始化
//无参数
//返回 Queue * 结点
Queue *initQueue();  // OK

//判断队列空
//参数：队列
//返回 1 为空，0 为非空
int isEmpty(Queue *q);  // OK

//入队
//参数：队列，结点
//无返回值
void Enqueue(Queue *q, Time_data *data);  // OK

//出队
//参数：队列
//返回 1 成功， 0 失败
int Out_Queue(Queue *q);  // OK

//得到队列中的结点数量
//参数：队列
//返回值：结点数量
int get_Queue_num(Queue *q);

/**
 * @brief 销毁队列
 * 
 */
void destory_queue(Queue *q);

/**
 * 欢迎函数
 */

//银行欢迎界面
void welcome();  // OK

//银行菜单界面
void menu();  // OK

//结束界面
void good_bye();

//初始化随机顾客
void init_custom(Queue *q);

/**
 * @brief 进入银行，银行菜单界面的入口
 *
 * @param q
 * @return int 返回 1 表示进入下一天
 *             返回 0 表示退出系统
 */
int Step_in(Queue *q);

/**
 * @brief 初始化窗口
 * 
 */
void init_windows();

//生成随机数
//返回随机数
int get_rand_num();  // OK

//根据随机数生成时间
//返回 Time 结构体
Time get_rand_time();

//将分钟数转换成 24进制 时间
Time turn_to_time(int min);

/**
 * @brief Get the leave time object
 *        这个函数实现的有点草率了
 * 
 * @param arrived_time
 */
void get_leave_time(Queue *q, Time_data *node);  // OK

//取号
//返回当前编号
//现在看起来没有用
//emm 好像确实没有用
//
//好吧还是有一点用
int get_serial_num(Queue *q);  // OK

/**
 * @brief 查询业务办理
 *
 * @param q
 */
void inquiry_business_handle(Queue *q);

/**
 * @brief Get the queue situation object
 *        and print it
 * @param q     队列
 * @param ti    输入的时间
 */
void get_queue_situation(Queue *q, Time input_time);

/**
 * @brief       判断该结点是否在输入时间段内在排序
 * 
 * @param t     队列结点
 * @param ti    输入的时间
 * @return int  0 没有找到 1 正在办理业务 2 正在排队 3 表示不用继续往后面找了
 */
int is_the_time(Time_data *t, Time input_time);

/**
 * @brief 比较两个24小时时间大小
 * 
 * @param ti1 
 * @param ti2 
 * @return int 返回 0 表示前者大，返回 1 表示后者大
 *             返回 2 表示两者时间相同
 */
int compare_time(Time ti1, Time ti2); //OK

/**
 * @brief 打印出正在排队的结点的信息
 * 
 * @param t 
 */
void print_wait_node(Time_data *t);

/**
 * @brief 打印出正在办理业务的结点信息
 * 
 * @param t 
 */
void print_deal_node(Time_data *t);

/**
 * @brief 打印结点信息
 * 
 * @param t 
 */
void print_node(Time_data *t);

/**
 * @brief 打印队列中每个结点的信息
 * 
 * @param q 
 */
void print_queue(Queue *q);

/**
 * @brief 对 VIP 用户进行插队处理
 * 
 * @param q 队列结点
 */ 
void sortQueue_vip(Queue *q);

/**
 * @brief 随机一个 VIP 用户
 * 
 * @return 返回 TRUE 为 VIP，返回 FALSE 为普通用户
 */
int if_is_vip();

#endif