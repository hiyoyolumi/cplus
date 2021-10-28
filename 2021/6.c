#include <stdio.h>

void func()
{
    short a = -2;
    unsigned int b = 1;
    b += a;
    printf("b = %d\n", b);
    int c = -1;
    unsigned short d = c * 256;
    printf("d = %hx\n", d);
    c <<= 4;
    int e = 2;
    e = ~e | 6;
    printf("e = %d\n", e);
    d = (d & 0xff) + 0x2022;
    printf("a = 0x%hx\tb=0x%x\td=0x%hx\te=0x%x\n", a, b, d, e);
    printf("c=0x%hhx\t\n", (signed char)c);
}

int main()
{
    func();

    return 0;
}