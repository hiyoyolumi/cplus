#include "HEAD.h"

void welcome() {
    printf("\e[37;40m ********************************** \e[0m\n");
    printf("\e[37;44m *         欢迎登录银行系统          * \e[0m\n");
    printf("\e[37;44m * Welcome to the banking system  * \e[0m\n");
    printf("\e[37;44m *                                * \e[0m\n");
    printf("\e[31;43m *          ****  ****            * \e[0m\n");
    printf("\e[31;43m *         ************           * \e[0m\n");
    printf("\e[31;43m *        **************          * \e[0m\n");
    printf("\e[31;43m *          **********            * \e[0m\n");
    printf("\e[31;43m *            ******              * \e[0m\n");
    printf("\e[31;43m *              **                * \e[0m\n");
    printf("\e[37;40m ********************************** \e[0m\n");
}

void menu() {
    printf("1. 取号\n");
    printf("2. 查询业务办理\n");
    printf("3. 系统查询\n");
    printf("4. 退出\n");
}

void good_bye() {
    printf("\e[37;44m Good Bye \e[0m\n");
}

int get_rand_num()  {
    srand((unsigned)time(NULL));
    int a = rand()%100;
    return a;
}

int get_serial_num(Queue *q) {
    //返回当前最大编号的下一位
    return q->rear->serial_num + 1;
}