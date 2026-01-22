#include <stdio.h>
int foo() {
    int a = 4;
    int b = 5;
    int x = a + b;
    return;
}

void main() {
    int val = foo();
    printf("val = %d\n", val);
}
