#include "HEAD.h"
#include "linklist.h"

#define MAX 100

#define FLAG 0

Window_status windows[WINDOW_NUMS];    //四个窗口 0 代表空闲 1 代表正在处理业务

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
            //退出程序
            break;
        }
    }

    return 0;
}

//测试环境
#else

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
