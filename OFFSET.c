#include<stdio.h>
int main() {
	int offset = 5;
//	offset += (4 - (offset % 4));
	offset = offset + (4 - (offset % 4));
	printf("%d\n", offset);
	return (0);
}
