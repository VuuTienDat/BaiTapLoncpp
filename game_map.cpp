#include <fstream>
#include "game_map.h"
using namespace std;
void GameMap::LoadMap( char* name) {
    FILE* fp = nullptr;
    fopen_s(&fp, name, "rb");
    if (fp == nullptr) {
        printf("Failed to open map file: %s\n", name);
        return;
    }

    game_map.max_x = 0;
    game_map.max_y = 0;
    for (int i = 0; i < MAX_MAP_Y; i++) {
        for (int j = 0; j < MAX_MAP_X; j++) {
            fscanf(fp, "%d", &game_map.tile[i][j]);
            int val = game_map.tile[i][j];
            if (val > 0) {

                if (j > game_map.max_x) {game_map.max_x = j; }
                if (i > game_map.max_y) {game_map.max_y = i;}
            }
        }
    }

    game_map.max_x = (game_map.max_x + 1) * TILE_SIZE ;
    game_map.max_y = (game_map.max_y + 1) * TILE_SIZE;
    game_map.start_x = 0;
    game_map.start_y = 0;
    game_map.file_name = name;
    fclose(fp);
}

void GameMap::LoadTiles(SDL_Renderer* screen) {
      for (int i = 0; i < MAX_TILES; i++) {
         std::string file_img = "map\\" + std::to_string(i) + ".png";
        const char* file_img_cstr = file_img.c_str();
        std::ifstream file(file_img);

        if (!file.is_open()) {
            continue;
        }

        file.close();

        tile_map[i].LoadImg(file_img_cstr, screen);
    }
}

void GameMap::DrawMap(SDL_Renderer* screen) {
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int map_x = 0;
    int map_y = 0;

    map_x = game_map.start_x / TILE_SIZE;
    map_y = game_map.start_y / TILE_SIZE;
    cerr << "start x " << game_map.start_x << endl;
    cerr << "map_x " << map_x << " map_y " << map_y << endl;

    x1 = (game_map.start_x % TILE_SIZE) * (-1);
    x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
    y1 = (game_map.start_y % TILE_SIZE) * (-1);
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);
    cerr << "x1:" << x1 << " x2:" << x2 << endl;
    cerr << "y1 " << y1 << " y2:" << y2 << endl;

    for (int i = y1; i < y2; i += TILE_SIZE) {


       map_x = game_map.start_x / TILE_SIZE;
        for (int j = x1; j < x2; j += TILE_SIZE)
        {

            int val = game_map.tile[map_y][map_x];
            if (val > 0)
            {

                tile_map[val].Set_Rect(j, i);
                tile_map[val].Render(screen,NULL);



            }
            map_x++;
        }
        map_y++;
    }
}
