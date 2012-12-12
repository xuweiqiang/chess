#ifndef CHESS_DRAW_H
#define CHESS_DRAW_H

extern int pieces[8][8];
extern char key[33];
extern void white_text(char *text);
extern void black_text(char *text);
extern void update_and_draw_board(int piece_id, char dest[2]);

#endif
