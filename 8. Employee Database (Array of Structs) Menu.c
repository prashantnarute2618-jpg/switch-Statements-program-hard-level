#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
};

struct Employee db[10]; // Database
int count = 0;

void addEmployee() {
    if (count == 10) {
        printf("Database full.\n"); return;
    }
    printf("Enter ID: ");
    scanf("%d", &db[count].id);
    printf("Enter Name: ");
    scanf("%s", db[count].name);
    count++;
    printf("Employee added.\n");
}

void listEmployees() {
    printf("--- Employee List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s\n", db[i].id, db[i].name);
    }
}

int main() {
    int choice;
    do {
        printf("\nDB MENU\n1. Add\n2. List\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: listEmployees(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid.\n"); break;
        }
    } while (choice != 3);
    return 0;
}