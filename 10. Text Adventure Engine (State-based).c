#include <stdio.h>

int main() {
    int currentRoom = 1; // 1: Hall, 2: Kitchen, 3: Library
    char command;
    int hasKey = 0; // 0=false, 1=true

    do {
        // State Description
        switch (currentRoom) {
            case 1:
                printf("\nYou are in a grand hall. There is a door to the (n)orth.\n");
                break;
            case 2:
                printf("\nYou are in a kitchen. There is a shiny (k)ey on the table. (s)outh to hall.\n");
                break;
            case 3:
                printf("\nYou are in a library. A large door is locked. (s)outh to hall.\n");
                break;
        }
        
        // Command Processing
        printf("> ");
        scanf(" %c", &command);
        
        // State Transition
        switch (currentRoom) {
            case 1: // Hall
                if (command == 'n') currentRoom = (hasKey) ? 3 : 2; // North
                if (command == 'n' && !hasKey) printf("The door is locked! You go to the kitchen instead.\n");
                if (command == 'n' && hasKey) printf("You unlock the door with the key!\n");
                break;
            case 2: // Kitchen
                if (command == 's') currentRoom = 1; // South
                if (command == 'k') {
                    hasKey = 1; printf("You took the key!\n");
                }
                break;
            case 3: // Library
                if (command == 's') currentRoom = 1; // South
                break;
        }
    } while (command != 'q'); // 'q' to quit
    
    return 0;
}