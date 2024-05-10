#ifndef _DEFS__H
#define _DEFS__H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
 static SDL_Renderer *Renderer_ = NULL;
 static SDL_Window *Window_   = NULL;
 static SDL_Event Event_ ;


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

  int jump_;



};
bool Check_Crash(const SDL_Rect &object1 ,const SDL_Rect &object2);
TTF_Font* loadFont(const char* path, int size);
SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor,SDL_Renderer * des);
Mix_Music *loadMusic(const char* path);
void play_Music(Mix_Music *gMusic, int check_);
Mix_Chunk* loadSound(const char* path);
void play_Chunk(Mix_Chunk* gChunk);


#define GRAVITY_SPEED 8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 10
#define BLANK_TILE 0
#define MONEY 4
#define Threat_Velocity 2;
#define Threat_Gravity 9;
#define Win_Flag 11




#define PLAY GAME 1
#define EXIT 2
#define CHOOSE_MUSIC 3
#define CHOOSE_SOUND 4


#define Play_Game 0
#define Exit_Game 1
#define Sound_Mode 2
#define On 3
#define Off 4
#define Play_Again 5
#define Win_Game 6
#define Loser 7

#define Turn_on 1
#define Turn_off 0


#define SHOW_MENU 2
#define EXIT_GAME_ 3
#define PLAY_GAME 4
#define SHOW_END_GAME 5
#define SHOW_WIN_GAME 6

#endif
