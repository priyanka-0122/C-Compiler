#include <stdio.h>
#include <stdlib.h>

extern int Token;

int main() {
        int *someptr = &Token;  // Used to simulate NULL check

        switch (Token) {
                case 3: {
                        // Simulates T_IDENT with NULL check
                        if (someptr == NULL) {
                                printf("Pointer is NULL -> treat as expression\n");
                                printf("Semicolon consumed\n");
                                return (0);
                        }
                }
                case 4:
                case 5:
                case 6:
                {
                        printf("frst\n");
                        return (0);
                }
                default:
                {
                        printf("default case\n");
                        printf("Semicolon consumed\n");
                        return (0);
        }
        }

return (0);
}
