#include <stdio.h>

FILE* file;
char* filename = "test.txt";

void writeFile() {
    file = fopen(filename, "w"); // "w" = write (overwrite)
    if (file == NULL) { printf("Error opening file.\n"); return; }
    fprintf(file, "Hello Adi!\nThis is line 2.\n");
    fclose(file);
    printf("File written.\n");
}

void readFile() {
    char line[100];
    file = fopen(filename, "r"); // "r" = read
    if (file == NULL) { printf("Error: File not found.\n"); return; }
    printf("--- Reading File ---\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
    printf("--------------------\n");
}

int main() {
    int choice;
    do {
        printf("\nFILE MENU\n1. Write File\n2. Read File\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: writeFile(); break;
            case 2: readFile(); break;
            case 3: break;
            default: printf("Invalid.\n"); break;
        }
    } while (choice != 3);
    return 0;
}