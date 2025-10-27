#include <stdio.h>

enum LightState { RED, GREEN, YELLOW };

int main() {
    enum LightState currentState = RED;
    
    // Simulate 5 ticks (e.g., 5 seconds)
    for (int tick = 1; tick <= 5; tick++) {
        printf("Tick: %d, State: ", tick);
        
        switch (currentState) {
            case RED:
                printf("RED (Stop)\n");
                // Transition logic
                if (tick % 2 == 0) { // Stay red for 2 ticks
                    currentState = GREEN;
                }
                break;
                
            case GREEN:
                printf("GREEN (Go)\n");
                // Transition logic
                currentState = YELLOW;
                break;
                
            case YELLOW:
                printf("YELLOW (Caution)\n");
                // Transition logic
                currentState = RED;
                break;
        }
    }
    return 0;
}