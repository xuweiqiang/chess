/*
 * Chess
 * Copyright (C) 2013 Michael Okner, Minneapolis, MN.
 *
 * An entirely terminal-based text Chess game.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <curses.h>
#include <term.h>
#include "game.h"

const char *version = "1.0.0";

const char *usage_string = 
    "Chess is a console-based chess game that can be run in any color terminal\n"
    "emulator. It is one-player only, and moves are specified using chess notation\n"
    "like Nxd3 or Bb5. It should be run with no arguments.";

char *colors() {
    /* User picks a number to determine who is black and white */
    int in, c, n;
    char *color;
    printf("Please enter a number between 1 and 10: ");
    scanf("%d", &in);
    c = in;
    srand(time(NULL));
    while (c == in)
        c = (rand() % 10) + 1;
    n = (rand() % 10) + 1;
    if (abs(n-c) > abs(n-in))
        color = "white";
    else
        color = "black";
    printf("The computer chose %d.\n", c);
    printf("The number to guess was %d.\n", n);
    printf("Your color is %s.\n", color);
    return color;
}

void env_check() {
    if (!isatty(1)) {
        fprintf(stderr, "Chess: output must be a standard terminal!\n");
        exit(1);
    }
    /* Check that colors are supported
    setupterm(NULL, fileno(stdout), (int *)0);
    int num_colors = tigetinfo("co");
    printf("Your terminal supports %d colors\n", num_colors);
    if (num_colors < 8) {
        printf("This game requires colors.\n");
        exit(1);
    }
    */
}

int main(int argc, const char **argv) {
    if (argc > 1) {
        printf("version: %s\n%s\n\n", version, usage_string);
        exit(1);
    }
    env_check();
    char *color;
    /* Show intro text and pick colors */
    printf("\033[2J\033[H");  /* ANSI Escape to clear terminal. */
    printf("CHESS v%s\n", version);
    printf("We will now select colors.\n");
    color = colors();
    /* Move on to gameplay */
    exit(run_game(color));
    return 1;
}
