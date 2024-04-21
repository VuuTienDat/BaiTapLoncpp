#ifndef MAIN_OBJECTS_H
#define MAIN_OBJECTS+H
#include "objects.h"
class MainObject : public objects
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
      void Set_MapXY(int map_x_, int map_y_);


      ~MainObject(){}

    public:
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



 };










#endif // MAIN_OBJECTS_H
