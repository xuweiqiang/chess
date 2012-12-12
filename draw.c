/*
 * This file contains the functions and code related to drawing and updating
 * the game board in the terminal as the game is played.
 *
 * The board will be a standard 80 columns for optimal compatibility.
 * In the future it may be altered to use ncurses if I feel it's worth the time
*/
#include <stdio.h>

char *white_text(char *text) {
    /* actually returns yellow text in case of white background. */
    char *formatted;
    sprintf(formatted, "\033[33m%s\033[0m", text);
    return formatted;
}

char *black_text(char *text) {
    /* actually returns blue text in case of black background */
    char *formatted;
    sprintf(formatted, "\033[34m%s\033[0m", text);
    return formatted;
}
