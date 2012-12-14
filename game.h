#ifndef CHESS_GAME_H
#define CHESS_GAME_H

/* extern int checkmate;
 * extern struct move; */
extern int run_game(char *player_color, int difficulty);
extern struct move get_player_move();
extern struct move exec_computer_move();

#endif
