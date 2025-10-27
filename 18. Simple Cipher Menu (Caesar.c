#include <stdio.h>
#include <string.h>

void caesar(char* s) {
    for(int i=0; s[i]!='\0'; i++) {
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = 'a' + ((s[i] - 'a' + 3) % 26);
    }
    printf("Caesar: %s\n", s);
}

void reverse(char* s) {
    int len = strlen(s);
    for(int i=0; i < len/2; i++) {
        char temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
    printf("Reverse: %s\n", s);
}

int main() {
    char str[100];
    int choice;
    printf("Enter string: ");
    scanf("%[^\n]s", str); // Read full line
    
    printf("CIPHER MENU\n1. Caesar (+3)\n2. Reverse\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            caesar(str);
            break;
        case 2:
            reverse(str);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}