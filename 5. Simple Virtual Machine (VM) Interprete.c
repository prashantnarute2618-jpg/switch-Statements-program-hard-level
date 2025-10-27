#include <stdio.h>

// Opcodes
#define PUSH 1
#define ADD  2
#define PRINT 3
#define HALT 0

int main() {
    int program[] = {PUSH, 5, PUSH, 10, ADD, PRINT, HALT};
    int stack[10];
    int sp = -1; // Stack Pointer
    int pc = 0;  // Program Counter

    int running = 1;
    while (running) {
        int instruction = program[pc];
        
        switch (instruction) {
            case PUSH:
                sp++; // Move stack pointer
                pc++; // Move to next instruction (the value)
                stack[sp] = program[pc];
                printf("Pushed %d\n", stack[sp]);
                break;
            case ADD:
                { // Braces needed to declare variables
                    int b = stack[sp--]; // Pop
                    int a = stack[sp--]; // Pop
                    sp++; // Push
                    stack[sp] = a + b;
                    printf("Added %d + %d = %d\n", a, b, stack[sp]);
                }
                break;
            case PRINT:
                printf("Top of stack: %d\n", stack[sp]);
                break;
            case HALT:
                printf("Program HALT.\n");
                running = 0;
                break;
            default:
                printf("Unknown instruction %d\n", instruction);
                running = 0;
                break;
        }
        pc++; // Go to next instruction
    }
    return 0;
}