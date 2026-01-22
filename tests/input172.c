#include <stdio.h>

int qbeprefix;
int a;
int b;
int c;

void  main()
{
a = 1;
b = 2;
c= 3;

qbeprefix = (a == 1 || b == 2 || c == 3) ? '$' : '%';
printf("the value is %c\n", qbeprefix);
qbeprefix = (a == 2 || b == 3 || c == 4) ? '$' : '%';
printf("the second value is %c\n", qbeprefix);
}
