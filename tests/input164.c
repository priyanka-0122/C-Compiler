#include <stdio.h>

void main() {
        int num = 4;
        int result = 0;
//        result = (num > 4)? result + num : result + 10;
        result += (num > 3)? num : 10;
        printf("result = %d\n", result);
}
