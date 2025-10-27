#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for atoi

int stack[20];
int top = -1;

void push(int v) { stack[++top] = v; }
int pop() { return stack[top--]; }

int main() {
    char* expr = "5 3 + 8 * 2 /"; // (5+3)*8 / 2 = 32
    char* token = strtok(expr, " ");

    while (token != NULL) {
        char op = token[0];

        switch (op) {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                {
                    int b = pop(); int a = pop();
                    push(a - b);
                }
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                {
                    int b = pop(); int a = pop();
                    push(a / b);
                }
                break;
            default:
                // It's a number
                push(atoi(token)); // Convert string to int
                break;
        }
        token = strtok(NULL, " ");
    }
    printf("RPN: %s\n", "5 3 + 8 * 2 /");
    printf("Result: %d\n", stack[top]);
    return 0;
}