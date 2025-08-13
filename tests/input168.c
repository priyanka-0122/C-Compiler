#include <stdio.h>

enum { CASE_1, CASE_2, CASE_3 };

void main()  {
	int x = CASE_1;
	switch (x) {
		case CASE_1:
			printf("In CASE_1\n");
		case CASE_2:
			printf("In CASE_2\n");
		case CASE_3:
			printf("In CASE_3\n");
	}
}
