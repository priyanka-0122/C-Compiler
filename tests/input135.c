#include <stdio.h>

int main() {
  int x, y;
  for (x=0; x < 4; x++)
    switch(x) {
      case 1: y = 1;
	      printf("y = %d\n", y);
      case 3:
      default: y = 20;
	       printf("y = %d\n", y);
	       break;
    }

  return(0);
}
