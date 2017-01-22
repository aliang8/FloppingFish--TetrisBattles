#ifndef TETRIMINO_H
#define TETRIMINO_H

//How many cells in orientation?
#define TETRIS 4
//How many tetriminos in our set?
#define NUM_TETRIMINOS 7
//How many orientations of a tetrimino?
#define NUM_ORIENTATIONS 4

//A row, column pair 
struct point {
  int x;
  int y;
};

//contains general info about a tetrimino - color, 
struct tetrimino {
  enum colors color;
  struct point rotations[4][4];
};

struct piece {
  struct tetrimino *tet;
  struct point pos;
  int rotid;
};

struct piece newpc();

typedef void (*mappc_fn)(struct piece pc, struct point pt, void *auxdata);

void mappc(struct piece pc, mappc_fn fn, void *auxdata);

void drawpc(struct piece pc, WINDOW *board, int color, int pad);

#endif
