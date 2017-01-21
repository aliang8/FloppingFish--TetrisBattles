#include <unistd.h>
#include "common.h"

#define TOP_BOUND   ((LINES - BRD_HEIGHT)/2)
#define LEFT_BOUND  ((COLS - BRD_WIDTH)/2)  
#define BRD_HEIGHT  28
#define BRD_WIDTH   26
#define HOLD_HEIGHT 3 
#define HOLD_WIDTH  6
#define INFO_HEIGHT 17
#define INFO_WIDTH  25
#define PAD         2

//bigger game 
#define COLS_PER_CELL 2
 
static struct {
  int score;
  WINDOW *board;
  WINDOW *hold;
  WINDOW *info;
  PANEL *board_p;
  PANEL *hold_p;
  PANEL *info_p;
} game;

void new_game(){
  game.score = 0;
  free_board();
  init_board(BRD_HEIGHT, BRD_WIDTH);
  //clear windows for refresh
  wclear(stdscr);
  wclear(game.board);
  wclear(game.hold);
}

void init_ncurses() {
  initscr(); //start curses mode
  noecho(); //don't echo keypresses
  cbreak();
  halfdelay(5);
  curs_set(false); //don't display cursor
  keypad(stdscr, true);
  srand(time(NULL));
  if (has_colors()) { //if terminal supports color
    start_color();
    //initialize color pairs
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLACK, COLOR_BLACK, COLOR_WHITE);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(ORANGE, COLOR_YELLOW, COLOR_YELLOW);
  } else {
    fprintf(stderr, "[Error] Terminal does not support colors. \n");
    endwin();
    exit(1);
  }
}

int main(){
  init_ncurses();
  game.board = newwin(BRD_HEIGHT + PAD,BRD_WIDTH + PAD,TOP_BOUND,LEFT_BOUND);
  game.hold = newwin(HOLD_HEIGHT + PAD,HOLD_WIDTH + PAD,TOP_BOUND,LEFT_BOUND + BRD_WIDTH + 2);
  game.info = newwin(INFO_HEIGHT + PAD,INFO_WIDTH + PAD,TOP_BOUND + HOLD_HEIGHT + 2,LEFT_BOUND + BRD_WIDTH + 2);
  game.board_p = new_panel(game.board);
  game.hold_p = new_panel(game.hold);
  game.info_p = new_panel(game.info);
  new_game();
  while(1){
    draw_board(game.board,game.hold);
    update_panels();
    doupdate();
  }
  return 0;
}
