#include "HEAD.h"
#include "linklist.h"

#define MAX 100

#define FLAG 1

#if FLAG

int main() {
    //重置随机数种子
    srand((unsigned)time(NULL));

    while (1) {
        //初始化队列
        Queue *q = initQueue();

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

int main() {
    srand((unsigned)time(NULL));
    Lnode *head;
    head = Create();
    sortList(head);
    print(head);
}

#endif
