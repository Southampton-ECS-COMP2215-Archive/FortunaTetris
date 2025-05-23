#include <stdio.h>
#include "lcd.h"
#include "color.h"

#define GRID_WIDTH 10

#define BLOCK_SIZE	15
#define SIDEBAR_START (BLOCK_SIZE*(GRID_WIDTH)) 

#define GRID_HEIGHT (LCDHEIGHT/BLOCK_SIZE)

#define BORDER_SIZE 2

extern volatile uint8_t block_grid [4][4];
extern volatile uint8_t virtual_grid [4][4];

typedef enum {I = CYAN_1, O = YELLOW_1, T = PURPLE_1, J = BLUE_1, L = ORANGE_1, S = GREEN_1, Z = RED_1} tetromino_type;

typedef struct {
	tetromino_type type;
	int16_t x, y, angle;
} tetromino;

void display_block(uint16_t x, uint16_t y, uint16_t color);
void draw_tetromino(tetromino_type piece, int16_t y, int16_t x, uint16_t angle, uint16_t color);
void display_tetromino(tetromino piece);
void clear_tetromino(tetromino piece);
int leftmost_block();
int rightmost_block();
int bottommost_block();
int leftmost_virtual_block();
int rightmost_virtual_block();
int bottommost_virtual_block();
void show_block_grid();
void adjust_virtual_grid(tetromino_type piece, uint16_t angle);
void update_block_grid();