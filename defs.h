#ifndef _DEFS__H
#define _DEFS__H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
 static SDL_Renderer *Renderer_ = NULL;
 static SDL_Window *Window_   = NULL;
 static SDL_Event Event_ ;
 static SDL_Surface *img_menu;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

const int FRAME_PER_SECOND = 25;
const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int RENDER_DRAW_COLOR = 0Xff;
#define TILE_SIZE 64
#define MAX_MAP_X 400
#define MAX_MAP_Y 10
#define MAX_TILES 20
#define TILE_SIZE 64

typedef struct Map{
    int start_x;
    int start_y;
    int max_x;
    int max_y;
    int tile[MAX_MAP_Y][MAX_MAP_X];
    char *file_name;

};
typedef struct Input{
  int left_;
  int right_;
  int up_;
  int down_;
  int jump_;



};
#define GRAVITY_SPEED 8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 10
#define BLANK_TILE 0






#define PLAY GAME 1
#define EXIT 2
#define CHOOSE_MUSIC 3
#define CHOOSE_SOUND 4


#endif
