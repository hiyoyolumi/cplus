#include <stdio.h>

struct node {
    int a;
    int b;
};

int main() {
    struct node *a, *b;
    a->a = 10;
    a->b = 20;
    b = a;
    b->a = 100;
    printf("%d", a->a);
}