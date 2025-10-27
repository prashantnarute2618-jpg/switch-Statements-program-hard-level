#include <stdio.h>

int main() {
    int month = 10; // October
    int year = 2025;
    int daysInMonth, startDay;
    
    // 1. Get days in month
    switch (month) {
        case 4: case 6: case 9: case 11:
            daysInMonth = 30; break;
        case 2:
            daysInMonth = (year % 4 == 0) ? 29 : 28; break;
        default:
            daysInMonth = 31; break;
    }
    
    // 2. Get start day (Simplified: Oct 1, 2025 is a Wednesday=3)
    startDay = 3; 
    
    // 3. Print Calendar
    printf("   Oct 2025\nSu Mo Tu We Th Fr Sa\n");
    
    // Print leading spaces
    for (int i = 0; i < startDay; i++) {
        printf("   ");
    }
    
    // Print days
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%2d ", day);
        if ((day + startDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}