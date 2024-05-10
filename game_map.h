#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "objects.h"
#include "defs.h"
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>

class TileMap : public objects {
public:
    TileMap() {}
    ~TileMap() {}
};

struct GameMap {
    GameMap() {}
    ~GameMap() {}
    Map game_map;

    TileMap tile_map[MAX_TILES];
    void LoadMap(char* name);
    void LoadTiles(SDL_Renderer* screen);
    void DrawMap(SDL_Renderer* screen);
    void set_start_x(const int& x){ game_map.start_x = x;}

};


#endif // GAME_MAP_H
