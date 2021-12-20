#include "HEAD.h"
#include "linklist.h"

#define MAX 100

#define FLAG 1

#if FLAG

int main() {
    //重置随机数种子
    srand((unsigned)time(NULL));
    //初始化随机顾客
    init_custom();
    //进入银行
    Step_in();


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
