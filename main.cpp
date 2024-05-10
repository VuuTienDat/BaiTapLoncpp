#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "logic.h"
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

        if(!IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)){cerr << "Error PNG" << endl;success = false;}

    }

  }

 if (TTF_Init() != 0)
    {
       SDL_Log("Loi khoi tao TTF");
    }

 if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) != 0 )
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR, "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }



  return success;
}



bool loadBackground()
{
   bool ret = g_background.LoadImg("img\\Back_ground1.jpg",Renderer_);
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
 Mix_Quit();

}
 vector <ThreatObjects*> Make_threat_list()
    {
       vector <ThreatObjects*> list_threat;
       ThreatObjects* threat_plus = new ThreatObjects[20];
       for(int i =0; i < 20 ;i++)
       {
           ThreatObjects* p_threat_plus = threat_plus+i;
          if(p_threat_plus != NULL)
          {
             p_threat_plus->LoadImg("img\\threat_left.png",Renderer_);
             p_threat_plus->set_clips();
             p_threat_plus->set_x_pos(500 + 1200 * i );
             p_threat_plus->set_y_pos(250);
             const int vi_tri_1 = p_threat_plus->get_x_pos()-100;
             const int vi_tri_2 = p_threat_plus->get_x_pos()+100;
             p_threat_plus->setAnimationPos(vi_tri_1,vi_tri_2);







            list_threat.push_back(p_threat_plus);
          }


       }
       return list_threat;
    }


int main(int argc, char *argv[]) {
   ImpTimer fps;
   if(!InitData()){cerr <<"Loi 1\n";}
   if(!loadBackground()){cerr << "Loi 2\n";}
      Mix_Music *BackGround = loadMusic("music\\backsound.mp3");
      Mix_Music *Music_Game = loadMusic("music\\playmusic.mid");
      Mix_Chunk *Bomer = loadSound("music\\Bomb2.wav");
      Mix_Chunk* Bomer1 = loadSound("music\\Bomb1.wav");
      Mix_Chunk *Fire = loadSound("music\\Fire1.wav");
      Mix_Chunk *ring = loadSound("music\\beep_.wav");
      Mix_Chunk *drop = loadSound("music\\drop.wav");



   MainObject player;
   player.LoadImg("img\\player_right.png",Renderer_);
   player.set_clips();
    GameMap Game_map;
    Game_map.LoadMap("map2\\map01.dat");
    Game_map.LoadTiles(Renderer_);
    vector <ThreatObjects*> threat_list = Make_threat_list();
  Exploitation_objects exploit ;
  exploit.LoadImg("img\\exploit.png",Renderer_);
  exploit.set_clips();
  Menu menu;
  menu.load_Img("img\\back_menu.jpg",Renderer_);
   graphic_ index;
   index.set_up(Renderer_);





  bool check = true;

    int x,y;
    int Heart =3;
    int Coins = 0;
    int mark_threat = 0;
    int mark_ = 0;

int  status = SHOW_MENU;
while(check){
    SDL_PollEvent(&Event_);

    if(Event_.type== SDL_QUIT){close(); break;}
  if(status == SHOW_MENU)
  {

     play_Music(BackGround,Turn_on);
     SDL_RenderClear(Renderer_);
     menu.Show_Menu(Renderer_);
     SDL_GetMouseState(&x,&y);
     menu.HanldeInputAction1(Event_,x,y,status);

     if(status == PLAY_GAME){

            play_Music(BackGround,Turn_off);
            threat_list.clear();
            threat_list = Make_threat_list();
            Heart = 3;
            Coins = 0;
            mark_ = 0;
            mark_threat = 0;
            player.set_money();
            player.set_x_dx();


            Game_map.LoadMap("map2\\map01.dat");

            }

     SDL_RenderPresent(Renderer_);



  }
 else if(status == EXIT_GAME_){check = false;break;}

  else if(status == PLAY_GAME){

          play_Music(Music_Game,menu.check_music_());

                SDL_RenderClear(Renderer_);
                g_background.Render(Renderer_,NULL);
                index.Show_(Renderer_, Heart,Coins,mark_);
                 Coins = player.get_money();
                 mark_ =Coins + mark_threat;



                player.HandleInputAction(Event_,Renderer_);
                if(player.get_check_bullet() == true){play_Chunk(Fire);}
                player.HandleBullet(Renderer_);
                player.Set_MapXY(Game_map.game_map.start_x);
                player.doPlayer(Game_map.game_map);
                player.Show(Renderer_);
                for(int i = 0; i < threat_list.size() ;i++)
                {
                   ThreatObjects *threat = threat_list.at(i);

                    if(threat != NULL)
                    {

                        threat->Set_MapXY(Game_map.game_map.start_x,Game_map.game_map.start_y);

                        threat->doPlayer(Game_map.game_map);
                        threat->ImMoveType(Renderer_);

                        threat->Show(Renderer_);


                    }


                }





                Game_map.DrawMap(Renderer_);

                vector <BulletObjects*>bullet_list = player.get_bullet_list();
                if(player.get_check_drop() == true){ play_Chunk(drop); Heart--;}

                  if(Heart == 0 )
                  {
                        play_Music(Music_Game,Turn_off);
                        status = SHOW_END_GAME;


                  }


                for(int j = 0; j < threat_list.size(); j++)
                {

                      SDL_Rect player_rect;
                      player_rect.x = player.get_rect().x;
                      player_rect.y = player.get_rect().y;
                      player_rect.w = player.get_rect().w/8;
                      player_rect.h = player.get_rect().h;

                    SDL_Rect threat_rect;
                      threat_rect.x = threat_list[j]->get_rect().x;

                      threat_rect.y = threat_list[j]->get_rect().y;

                      threat_rect.w = threat_list[j]->get_rect().w/8;
                      threat_rect.h = threat_list[j]->get_rect().h;

                   if(Check_Crash(player_rect,threat_rect))
                      {
                         play_Chunk(Bomer1);
                          for(int i =0 ; i < 8;i++)
                            {
                                exploit.Set_Rect(player_rect.x -40 , player_rect.y -40);
                                exploit.show(Renderer_);
                                SDL_RenderPresent(Renderer_);
                                SDL_Delay(50);
                            }





                          if(player.get_come_back_time() == 0){Heart--; }



                          if(Heart == 0 )
                          {
                            play_Music(Music_Game,Turn_off);
                            status = SHOW_END_GAME;


                          }
                      player.set_come_back_time(1);

                      }


                  for(int i = 0; i < bullet_list.size() ; i++)
                  {


                      if(Check_Crash(bullet_list[i]->get_rect(), threat_rect))
                      {  play_Chunk(Bomer);
                          int m = threat_rect.x; int n = threat_rect.y;

                         threat_list[i]->Freedom();
                         threat_list[i] = nullptr;
                          threat_list.erase(threat_list.begin()+j);
                          mark_threat++;


                             for(int k =0 ; k < 8;k++)
                            {
                                exploit.Set_Rect(m - 40, n -40);
                                exploit.show(Renderer_);
                                SDL_RenderPresent(Renderer_);
                                SDL_Delay(20);
                            }

                       if(bullet_list[i]->get_bullet_dir() == bullet_list[i]->DIR_RIGHT)
                       {
                          bullet_list[i]->Set_Rect(1280 ,0);

                       }
                       else{
                        bullet_list[i]->Set_Rect(0,0);
                       }


                      }








                  }


                }

                if(player.get_check_win() == true){
                        play_Music(Music_Game,Turn_off);
                        status= SHOW_WIN_GAME;
                }






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
   else if(status == SHOW_END_GAME){

             play_Music(BackGround,Turn_on);
             SDL_RenderClear(Renderer_);
             menu.Show_EndGame(Renderer_,mark_);
             SDL_GetMouseState(&x,&y);
             menu.HanldeInputAction2(Event_,x,y,status);
              if(status == SHOW_MENU)
                {play_Music(BackGround,Turn_off);}

             player.set_x_pos(0);

             Game_map.set_start_x(0);









             SDL_RenderPresent(Renderer_);
             }

  else if( status == SHOW_WIN_GAME)
  {          play_Music(BackGround,Turn_on);
             SDL_RenderClear(Renderer_);
             menu.Show_Win(Renderer_,mark_);
             SDL_GetMouseState(&x,&y);
             menu.HanldeInputAction2(Event_,x,y,status);
             if(status == SHOW_MENU)
                {player.set_play_again(); play_Music(BackGround,Turn_off);}
             player.set_x_pos(0);

             Game_map.set_start_x(0);
             SDL_RenderPresent(Renderer_);



  }


}
  for(int i = 0; i < threat_list.size();i++)
  {
      if(threat_list[i] != nullptr)
      {
          threat_list[i]->Freedom();
          threat_list[i] = nullptr;
      }
  }
 threat_list.clear();

  if(BackGround != nullptr)
  {
      Mix_FreeMusic(BackGround);
      BackGround = nullptr;
  }
  if(Bomer1!= nullptr)
  {
      Mix_FreeChunk(Bomer1);
      Bomer1 = nullptr;

  }
   if(Bomer!= nullptr)
  {
      Mix_FreeChunk(Bomer);
      Bomer = nullptr;

  }
   if(Fire!= nullptr)
  {
      Mix_FreeChunk(Fire);
      Fire = nullptr;

  }
  if(ring!= nullptr)
  {
      Mix_FreeChunk(ring);
      ring = nullptr;

  }
   if(drop!= nullptr)
  {
      Mix_FreeChunk(drop);
      drop = nullptr;

  }

  menu.free();
  player.Freedom();



  close();






    return 0;
}





