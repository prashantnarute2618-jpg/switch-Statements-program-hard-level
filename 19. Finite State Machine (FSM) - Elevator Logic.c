#include <stdio.h>

enum State { IDLE, MOVING_UP, MOVING_DOWN };

int main() {
    enum State state = IDLE;
    int currentFloor = 1;
    int floorRequest = 5;
    
    printf("Elevator at floor %d. State: IDLE\n", currentFloor);
    printf("Request for floor %d.\n", floorRequest);
    
    while (currentFloor != floorRequest) {
        switch (state) {
            case IDLE:
                if (floorRequest > currentFloor) state = MOVING_UP;
                else state = MOVING_DOWN;
                break;
            
            case MOVING_UP:
                currentFloor++;
                printf("Moving UP... at floor %d\n", currentFloor);
                if (floorRequest < currentFloor) state = MOVING_DOWN;
                break;
                
            case MOVING_DOWN:
                currentFloor--;
                printf("Moving DOWN... at floor %d\n", currentFloor);
                if (floorRequest > currentFloor) state = MOVING_UP;
                break;
        }
    }
    
    printf("Arrived at floor %d. State: IDLE\n", currentFloor);
    state = IDLE;
    return 0;
}