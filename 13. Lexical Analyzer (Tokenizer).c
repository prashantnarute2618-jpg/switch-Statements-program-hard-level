#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[] = "a = 10 + 20;";
    printf("Parsing: %s\n", input);
    
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        
        switch (c) {
            case ' ':
            case '\t':
                break; // Ignore whitespace
            case '+':
                printf("TOKEN: OPERATOR (+)\n");
                break;
            case '=':
                printf("TOKEN: OPERATOR (=)\n");
                break;
            case ';':
                printf("TOKEN: SEMICOLON (;)\n");
                break;
            default:
                if (isalpha(c)) {
                    printf("TOKEN: IDENTIFIER (%c)\n", c);
                    // A real lexer would read the whole word
                } else if (isdigit(c)) {
                    printf("TOKEN: NUMBER (%c)\n", c);
                    // A real lexer would read the whole number
                }
                break;
        }
    }
    return 0;
}