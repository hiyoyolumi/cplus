#include <stdio.h>

struct node {
    int a;
    int b;
};

#define INT int

int num_birth = 10;

int main() {
    INT a;
    printf("sizeof = %d\n", sizeof(INT));
    return 0;
}