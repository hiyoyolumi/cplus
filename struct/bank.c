#include "HEAD.h"

//走进银行
void Step_in() {
    //打印银行欢迎界面
    welcome();
    
    //初始化队列
    Queue *q = initQueue();
    if (q == NULL) {
        printf("队列初始化失败\n");
        return;
    }
    int flag = 1;
    while (flag) {
        //打印菜单界面
        menu();

        int temp;
        scanf("%d", &temp);
        switch (temp)
        {
        case 1:
            //取号
            system_serial();
            break;
        case 2:

            break;
        case 3:

            break;

        case 4:
            flag = 0;
            break;

        default:
            printf("请输入指定序号\n");
            break;
        }
    }
}

int system_serial() {
    Time_data *p = (Time_data *)malloc(sizeof(Time_data));
    p->arrivd_time = get_rand_num();
    p->business_time = 30;
    // p->star_time = 
}