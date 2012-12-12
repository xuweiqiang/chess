/* This file contains the code that handles the actual gameplay.
 * It acts as a sort of boss that calls various functions to
 * do the actual drawing and caculations and such.
 */

#include <stdio.h>
#include <stdlib.h>

int run_game(char *player_color, int difficulty) {
    /* Called by main() in chess.c to start the gameplay */
    printf("run_game() function called.\n");
    printf("The player will be %s and the difficulty setting is %d.\n", player_color, difficulty);
    return 1;
}
