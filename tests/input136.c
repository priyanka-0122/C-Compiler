#include <stdio.h>

int main() {
  int x, y;
  for (x=0; x < 5; x++)
    switch(x) {
      case 1: y = 1;
	      printf("y = %d\n", y);
      case 3: y = 3;
	      printf("y = %d\n", y);
	      break;
      default:
    }

  return(0);
}
