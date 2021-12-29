#include "HEAD.h"
#include "linklist.h"

#define MAX 100

#define FLAG 1

Window_status windows[WINDOW_NUMS];    //四个窗口 0 代表空闲 1 代表正在处理业务
Window_status VIP_window;              //VIP窗口

#if FLAG

int main() {
    //重置随机数种子
    srand((unsigned)time(NULL));

    while (1) {
        //初始化队列
        Queue *q = initQueue();

        //初始化窗口
        init_windows();

        //初始化随机顾客 并 存入 队列 中
        init_custom(q);

        //进入银行
        if (!Step_in(q)) {
            //销毁队列
            destory_queue(q);
            //退出程序
            good_bye();
            break;
        }
        //销毁队列
        destory_queue(q);
    }


    return 0;
}

//测试环境
#else

void print_node(Time_data *t) {
    printf("-------------------------");
    printf("客户编号：%d\n", t->serial_num);
    printf("办理业务窗口：%d\n", t->window_serial);
    printf("到达时间：%d:%d\n", t->arrivd_time.min_h, t->arrivd_time.min_min);
    printf("开始时间：%d:%d\n", t->star_time.min_h, t->star_time.min_min);
    printf("离开时间：%d:%d\n", t->leave_time.min_h, t->leave_time.min_min);
    printf("办理业务时间：%d (min)\n", t->business_time);
    printf("-------------------------\n");
}
void print_queue(Queue *q) {
    while (!isEmpty(q)) {
        print_node(q->front->next);
        Out_Queue(q);
    }
}

int main() {
    srand((unsigned)time(NULL));
    Queue *q = initQueue();
    init_custom(q);
    // Time_data *p = (Time_data *)malloc(sizeof(Time_data));
    // p->serial_num = 111;
    // Enqueue(q, p);
    // p->serial_num = 222;
    // Enqueue(q, p);
    print_queue(q);

    return 0;
}

// int main() {
//     srand((unsigned)time(NULL));
    
//     Queue *q = initQueue();
//     // printf("%d\n", __LINE__);
//     init_windows();
//     // printf("%s : %d\n", __FILE__, __LINE__);
//     init_custom(q);
//     printf("%s : %d\n", __FILE__, __LINE__);
//     print_queue(q);

//     return 0;
// }


// int main() {
//     srand((unsigned)time(NULL));
//     Lnode *head;
//     head = Create();
//     sortList(head);
//     print(head);
// }

#endif
