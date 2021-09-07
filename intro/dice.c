#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    srand(time(NULL));

    // NdM  3d6 2d8

    int dice_dices[argc-1];
    int dice_sides[argc-1];


    for (int i = 1; i < argc; i++) {
        if (sscanf(argv[i], "%dd%d", &dice_dices[i - 1], &dice_sides[i - 1]) == 2) {
        } else if (sscanf(argv[1], "d%d", &dice_sides[i - 1]) == 1) {
            dice_dices[i-1] = 1;
        } else {
            printf("Not a dice roll: %s\n", argv[i]);
            return 1;
        }
    }

    for (int i = 0; i < argc-1; i++) {
        int sum = 0;
        for (int j = 0; j < dice_dices[i]; j++) {
            int x = rand() % dice_sides[i] + 1;
            sum = sum + x;
        }
        printf("Rolled %d %d-sided dice; sum: %d\n",
           dice_dices[i], dice_sides[i], sum);
    }
}
