/* This file contains the code that handles the actual gameplay.
 * It acts as a sort of boss that calls various functions to
 * do the actual drawing and caculations and such.
 */

#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

int run_game(char *player_color, int difficulty) {
    /* Called by main() in chess.c to start the gameplay */
    update_and_draw_board(-1, "b3");
    printf("\nUser color is %s and difficulty is %d\n", player_color, difficulty);
    return 0;
}
