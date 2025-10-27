#include <stdio.h>

enum State { IDLE, HAS_COIN, ITEM_SELECTED };
enum Input { INSERT_COIN, SELECT_ITEM, TAKE_ITEM };

int main() {
    enum State currentState = IDLE;
    enum Input input;
    
    // Simulate user inputs
    enum Input inputs[] = {INSERT_COIN, SELECT_ITEM, TAKE_ITEM};
    int input_count = 3;

    for (int i = 0; i < input_count; i++) {
        input = inputs[i];
        
        switch (currentState) {
            case IDLE:
                printf("State: IDLE\n");
                if (input == INSERT_COIN) {
                    printf("  Input: INSERT_COIN -> State: HAS_COIN\n");
                    currentState = HAS_COIN;
                } else {
                    printf("  Input: %d -> Invalid. Insert coin first.\n", input);
                }
                break;
                
            case HAS_COIN:
                printf("State: HAS_COIN\n");
                if (input == SELECT_ITEM) {
                    printf("  Input: SELECT_ITEM -> Dispensing... -> State: ITEM_SELECTED\n");
                    currentState = ITEM_SELECTED;
                } else {
                    printf("  Input: %d -> Invalid. Select item.\n", input);
                }
                break;
                
            case ITEM_SELECTED:
                printf("State: ITEM_SELECTED\n");
                if (input == TAKE_ITEM) {
                    printf("  Input: TAKE_ITEM -> Thank you! -> State: IDLE\n");
                    currentState = IDLE;
                } else {
                    printf("  Input: %d -> Invalid. Take your item.\n", input);
                }
                break;
        }
    }
    return 0;
}