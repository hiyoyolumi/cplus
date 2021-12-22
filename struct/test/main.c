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

    Time arrivd_time;   //到达时间
    int wait_time;      //等待时间 要不要的吧
    Time leave_time;    //离开时间
    int business_time;  //办理业务时间 固定为 10 ，后续完善的话可以将其改为随机数(1~60)
    Time star_time;     //开始办理时间
    struct Node *next;
} Time_data;

typedef struct Queue {
    Time_data *head;  //存放队列头结点

    Time_data *front;
    Time_data *rear;
} Queue;


//队列初始化
Queue *initQueue() {
    Queue *q;
    Time_data *p;

    q = (Queue *)malloc(sizeof(Queue));
    p = (Time_data *)malloc(sizeof(Time_data));  //这里的 p 是头结点
    p->next = NULL;
    q->head = q->front = q->rear = p;
    //初始化头结点编号为 0
    q->rear->serial_num = 0;
    if (!q->front) {
        return NULL;
    }
    return q;
}
//判断队空
int isEmpty(Queue *q) {
    if (q->front == q->rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}
//入队
void Enqueue(Queue *q, Time_data *data) {
    Time_data *p;
    p = (Time_data *)malloc(sizeof(Time_data));

    //把传入的参数复制给分配的地址
    p->serial_num = data->serial_num;
    p->arrivd_time = data->arrivd_time;
    p->wait_time = data->wait_time;
    p->leave_time = data->leave_time;
    p->business_time = data->business_time;
    p->star_time = data->star_time;
    printf("%d\n", __LINE__);
    p->next = NULL;

    q->rear->next = p;
    printf("%d\n", __LINE__);
    q->rear = p;
    printf("%d\n", __LINE__);
}

int Out_Queue(Queue *q) {
    if (isEmpty(q)) {
        // TODO 感觉之后会在这里添东西
        printf("当前没有人排队\n");
        return 0;
    } else {
        //出队后 front 指向队头，出队的结点不会被释放
        q->front = q->front->next;
        if (q->front->next == NULL) {
            q->front = q->rear;
        }
        return 1;

        //出队后 front 仍指向头结点
        // Time_data *p;
        // p = q->front->next;
        // q->front->next = p->next;
        // free(p);
        // if (q->front->next == NULL) {
        //     q->rear = q->front;
        // }
        // return 1;
    }
}

void print_node(Time_data *t) {
    printf("-------------------------");
    printf("客户编号：%d\n", t->serial_num);
    printf("办理业务窗口：%d\n", t->window_serial);
    printf("到达时间：%d\n", t->arrivd_time);
    printf("开始时间：%d\n", t->star_time);
    printf("离开时间：%d\n", t->leave_time);
    printf("办理业务时间：%d\n", t->business_time);
    printf("-------------------------");
}
void print_queue(Queue *q) {
    while (!isEmpty(q)) {
        print_node(q->front);
        Out_Queue(q);
    }
}

int main() {
    srand((unsigned)time(NULL));
    Queue *q = initQueue();
    Time_data *p;
    p->serial_num = 111;
    Enqueue(q, p);
    p->serial_num = 222;
    Enqueue(q, p);
    print_queue(q);

    return 0;
}