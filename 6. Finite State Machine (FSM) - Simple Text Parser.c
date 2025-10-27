#include <stdio.h>
#include <string.h>

enum State { OUTSIDE, INSIDE };

int main() {
    char text[] = "This is \"a quoted string\" and this is \"another one with \\\" escaped quotes\\\".";
    enum State currentState = OUTSIDE;
    
    printf("Parsing string: %s\n", text);
    printf("Found: ");
    
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        
        switch (currentState) {
            case OUTSIDE:
                if (c == '\"') {
                    currentState = INSIDE; // Enter quote
                }
                break;
                
            case INSIDE:
                if (c == '\\' && text[i+1] == '\"') {
                    // This is an escaped quote, print it
                    printf("%c", text[i+1]);
                    i++; // Skip the next char
                } else if (c == '\"') {
                    currentState = OUTSIDE; // Exit quote
                    printf(" | "); // Separator
                } else {
                    printf("%c", c); // Print char
                }
                break;
        }
    }
    printf("\nDone.\n");
    return 0;
}