#include <stdio.h>

// 1 = 001 (Execute)
// 2 = 010 (Write)
// 4 = 100 (Read)
#define PERM_X 1
#define PERM_W 2
#define PERM_R 4

void printPerms(int p) {
    printf("Permissions: [");
    printf((p & PERM_R) ? "R" : "-");
    printf((p & PERM_W) ? "W" : "-");
    printf((p & PERM_X) ? "X" : "-");
    printf("] (int: %d)\n", p);
}

int main() {
    int permissions = 0; // Start with no perms
    char op;
    char type;
    
    do {
        printPerms(permissions);
        printf("Enter op (+ or -) and type (r, w, x). (q to quit): ");
        scanf(" %c", &op);
        if(op == 'q') break;
        scanf(" %c", &type);
        
        switch (op) {
            case '+': // Add permission
                switch (type) {
                    case 'r': permissions = permissions | PERM_R; break;
                    case 'w': permissions = permissions | PERM_W; break;
                    case 'x': permissions = permissions | PERM_X; break;
                }
                break;
            case '-': // Remove permission
                switch (type) {
                    case 'r': permissions = permissions & ~PERM_R; break;
                    case 'w': permissions = permissions & ~PERM_W; break;
                    case 'x': permissions = permissions & ~PERM_X; break;
                }
                break;
        }
    } while(1);
    return 0;
}