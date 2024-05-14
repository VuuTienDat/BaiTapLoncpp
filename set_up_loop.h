#ifndef SET_UP_LOOP_H
#define SET_UP_LOOP_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "game_map.h"
#include "objects.h"
#include "MainObjects.h"
#include "ImpTimer.h"
#include "BulletObjects.h"
#include <SDL_ttf.h>
#include "ThreatObjects.h"
#include "Exploitation_objects.h"
#include <SDL_mixer.h>
#include "Menu.h"
#include "graphic_.h"
using namespace std;


struct Loop_{
    objects g_background;
    MainObject player;
    Menu menu;
    graphic_ index;
    GameMap Game_map;
    Exploitation_objects exploit;
    vector <ThreatObjects*> threat_list;
    vector <ThreatObjects*> Make_threat_list();

      Mix_Music *Music_Game = nullptr;
      Mix_Chunk *Bomer = nullptr;
      Mix_Chunk* Bomer1 = nullptr;
      Mix_Chunk *Fire = nullptr;
      Mix_Chunk *drop = nullptr;
      Mix_Music *BackGround = nullptr;
      Mix_Music *Music_win = nullptr;
      Mix_Music *Music_Lose = nullptr;
    int Heart =3;
    int Coins = 0;
    int mark_threat = 0;
    int mark_ = 0;


    void set_up_sound();
    void set_up();
    void set_up_Menu();
    void close_object();
    void close_all();
    bool InitData();
    bool loadBackground();

    void play_game_happy();
    void Free();








};

#endif // SET_UP_LOOP_H
