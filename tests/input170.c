#include <stdio.h>

int foo() {
	printf("12345\n");
	return;
}

void main() {
	int val = foo();
	printf("val= %d\n", val);
}
