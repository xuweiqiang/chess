/* This file contains the code that handles the actual gameplay.
 * It acts as a sort of boss that calls various functions to
 * do the actual drawing and caculations and such.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "draw.h"

int checkmate = 0;
struct move {
    int id;
    char *dest;
};

/* XXX Moves are temporarily hardcoded */

struct move get_player_move() {
    /* Receive a command and parse it into a piece id and movement */
    char cmd[11];
    struct move send;
    printf("\nEnter a command: ");
    fgets(cmd, 10, stdin);
    send.id = 13;
    send.dest = "e3";
    return send;
}

struct move exec_computer_move() {
    /* Calculate options and pick one based on the
     * specified difficulty level */
    struct move send;
    send.id = 21;
    send.dest = "e6";
    return send;
}

int run_game(char *player_color, int difficulty) {
    /* Called by main() in chess.c to start and manage the gameplay */
    update_and_draw_board(-1, "xx");
    struct move stored;
    /*if (player_color == "black") {
        stored = exec_computer_move();
        update_and_draw_board(stored.id, stored.dest);
    }*/
    while (checkmate == 0) {
        stored = get_player_move();
        update_and_draw_board(stored.id, stored.dest);
        stored = exec_computer_move();
        update_and_draw_board(stored.id, stored.dest);
        checkmate = 1;
        printf("\n\n");
    }
    return 0;
}
