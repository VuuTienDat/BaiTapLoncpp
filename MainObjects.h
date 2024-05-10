#ifndef MAIN_OBJECTS_H
#define MAIN_OBJECTS+H
#include "objects.h"
#include <vector>
#include "BulletObjects.h"
using namespace std;
class MainObject: public objects
 {

    public :
       MainObject();

      enum WalkType{
       WALK_RIGHT = 0,
       WALK_LEFT  = 1,


      };
      virtual bool LoadImg(const char *s,SDL_Renderer* screen);
      void Show(SDL_Renderer *des);
      void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
      void set_clips();
      void doPlayer(Map& map_data);
      void CheckToMap(Map& map_data);
      void Set_Moving_Map(Map& map_data);
      void Set_MapXY(int moving_x);
      void UpdateImagePlayer(SDL_Renderer* des);
       void set_bullet_list(vector<BulletObjects*> bullet_list_)
       {
          bullet_list = bullet_list_;
       }
     vector <BulletObjects*> get_bullet_list(){return bullet_list;}
      void HandleBullet(SDL_Renderer* des);

      void set_come_back_time(const int &come_back){come_back_time = come_back;}
      int get_come_back_time(){return come_back_time;}
      bool get_check_win(){return check_win;}
      bool get_check_drop(){return check_drop;}
      bool get_check_bullet(){return check_bullet;}
      void set_x_pos(const int& x){x_pos = x;}
      void set_play_again(){ check_win = false;}
     void set_x_dx(){x_dx= 0 ;}


      int get_money(){return count_money;}
      void set_money(){count_money = 0;}


      ~MainObject(){Mix_FreeChunk(bell);bell = nullptr;}

    private:
        vector <BulletObjects*> bullet_list;
        float x_dx;
        float y_dy;

       float x_pos;
       float y_pos;
       int width_frame ;
       int height_frame ;
       SDL_Rect frame_clip[8];
       Input input_type;
       int frame;
       int status_move;
       bool on_ground;
       int map_x_ , map_y_;

       int come_back_time;
       int count_money;

    bool check_drop;
    bool check_bullet;
    bool check_win;

    Mix_Chunk *bell = nullptr;


 };










#endif // MAIN_OBJECTS_H
