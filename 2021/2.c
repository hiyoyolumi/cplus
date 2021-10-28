#include <stdio.h>

struct test1
{
    int a;
    short b;
    double c;
};

struct test2
{
    short b;
    int a;
    double c;
};

int main()
{
    struct test1 t1;
    struct test2 t2;

    printf("%d %d\n", sizeof(t1), sizeof(t2));

    return 0;
}