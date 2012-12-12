/*
 * This file contains the functions and code related to drawing and updating
 * the game board in the terminal as the game is played.
 *
 * The board will be a standard 80 columns for optimal compatibility.
 * In the future it may be altered to use ncurses if I feel it's worth the time
 *
 * Design:
 * A chess board is 8 x 8.
 * Each piece will be a bold letter.
 * Borders will be 1 char
 * Spaces will be 8 chars wide and 3 chars tall
 * Around the outside will be coordinate labels
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pieces[8][8] = {
    { 1,  2,  3,  4,  5,  6,  7,  8},
    { 9, 10, 11, 12, 13, 14, 15, 16},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    {17, 18, 19, 20, 21, 22, 23, 24},
    {25, 26, 27, 28, 29, 30, 31, 32}
};
char keystr[34] = "-RNBQKBNRooooooooooooooooRNBQKBNR";

void white_text(char *text) {
    /* actually makes text bold yellow */
    int i = strlen(text);
    char tmp[i];
    sprintf(tmp, "\033[1;33m%s\033[0m", text);
    strcpy(text, tmp);
}

void black_text(char *text) {
    /* actually makes text bold blue */
    int i = strlen(text);
    char tmp[i];
    sprintf(tmp, "\033[1;34m%s\033[0m", text);
    strcpy(text, tmp);
}

void update_and_draw_board(int piece_id, char dest[3]) {
    /* Draws the board on the screen.
     * Argument can be an move or empty for the initial run.
     * piece_id is an internal identifier for each piece,
     * and dest[2] is the coordinate of the destination.
    */
    if (piece_id != -1) {
        /* Update the coordinates */
        printf("Not implemented.\n");
    }
    /* Draw the board */
    int i, row, key;
    char name[25];
    printf("\033[2J\033[H");
    printf("Mike Okner's CHESS\n");
    printf("      a        b        c        d        e        f        g        h\n");
    printf("  -------------------------------------------------------------------------\n");
    for (row=7; row>=0; row--) {
        printf("  |        |        |        |        |        |        |        |        |\n");
        printf("%d |", row + 1);
        for (i=0; i<8; i++) {
            key = pieces[row][i];
            snprintf(name, 2, "%c", keystr[key]);
            // fprintf(stderr, "row: %d, col: %d, id: %d, piece: %s\n", row, i, key, name);
            if (key > 0 && key <= 16)
                white_text(name);
            else if (key > 0 && key >= 17)
                black_text(name);
            else
                snprintf(name, 2, " ");
            printf("   %s    |", name);
        }
        printf(" %d\n", row + 1);
        printf("  |        |        |        |        |        |        |        |        |\n");
        printf("  -------------------------------------------------------------------------\n");
    }
    printf("      a        b        c        d        e        f        g        h\n");
}
