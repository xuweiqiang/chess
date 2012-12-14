#ifndef CHESS_DRAW_H
#define CHESS_DRAW_H

extern int pieces[8][8];
extern char keystr[34];
/* extern struct xy; */
extern void white_text(char *text);
extern void black_text(char *text);
extern struct xy get_curr_coords(int piece_id);
extern void update_and_draw_board(int piece_id, char dest[3]);
extern void update_and_draw_board(int piece_id, char dest[2]);

#endif
