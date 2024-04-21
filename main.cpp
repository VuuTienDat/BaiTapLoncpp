#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "logic.h"
#include "game_map.h"
#include "objects.h"
#include "MainObjects.h"
#include "ImpTimer.h"
#include <SDL_ttf.h>
using namespace std;

 objects g_background;
   bool InitData()

{
  bool success = true;
  if(SDL_Init(SDL_INIT_VIDEO) !=0){return false;}

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
  Window_ = SDL_CreateWindow("Game_project",SDL_WINDOWPOS_UNDEFINED
                             ,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if(Window_== NULL){cerr << "Error Window" << endl;success = false;}
  else{
    Renderer_ = SDL_CreateRenderer(Window_,-1,SDL_RENDERER_ACCELERATED);
    if(Renderer_== NULL){cerr << "Error Renderer_" << endl;success = false;}
    else{
        SDL_SetRenderDrawColor(Renderer_,RENDER_DRAW_COLOR,0,0,RENDER_DRAW_COLOR);
        if(!IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)){cerr << "Error PNG" << endl;success = false;}

    }

  }

 if (TTF_Init() != 0)
    {
       SDL_Log("Loi khoi tao TTF");
    }


  return success;
}



bool loadBackground()
{
   bool ret = g_background.LoadImg("img\\Background.jpg",Renderer_);
  if(ret == false){return false;}
   return true;
}
void close(){
 g_background.Freedom();
 SDL_DestroyRenderer(Renderer_);
 Renderer_= NULL;
 SDL_DestroyWindow(Window_);
 Window_ = NULL;
 IMG_Quit();
 SDL_Quit();
 TTF_Quit();

}





int main(int argc, char *argv[]) {
   ImpTimer fps;

   if(!InitData()){cerr <<"Loi 1\n";}
   if(!loadBackground()){cerr << "Loi 2\n";}

   MainObject player;
   player.LoadImg("img\\player_right.png",Renderer_);
   player.set_clips();



    GameMap Game_map;
    Game_map.LoadMap("map\\map01.dat");
    Game_map.LoadTiles(Renderer_);

while(true){
    SDL_PollEvent(&Event_);
    if(Event_.type== SDL_QUIT|| Event_.type == SDL_MOUSEBUTTONDOWN){close(); break;}



    SDL_RenderClear(Renderer_);
    g_background.Render(Renderer_,NULL);



    player.HandleInputAction(Event_,Renderer_);
    player.Set_MapXY(Game_map.game_map.start_x,Game_map.game_map.start_y);
    player.Show(Renderer_);
    player.doPlayer(Game_map.game_map);
     Game_map.DrawMap(Renderer_);
    SDL_RenderPresent(Renderer_);
    int real_imp_time = fps.get_ticks();
    int time_one_frame = 900/FRAME_PER_SECOND;
    if(real_imp_time < time_one_frame)
    {
        int delay_time = time_one_frame - real_imp_time;
        if(delay_time >= 0)
          {
              SDL_Delay(delay_time);
          }

    }

}
  close();






    return 0;
}





