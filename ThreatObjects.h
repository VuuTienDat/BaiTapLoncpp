#ifndef THREATOBJECTS_H
#define THREATOBJECTS_H
#include "defs.h"
#include "objects.h"
#include "BulletObjects.h"
#include <vector>

using namespace std;

class ThreatObjects : public objects
{
    public:
      ThreatObjects();
      ~ThreatObjects();
      enum Threat_Dir{
        MOVE_LEFT = 100,
        MOVE_RIGHT = 101,
      };



      void set_x_dx(const float& xdx){x_dx = xdx;}
      void set_y_dy(const float& ydy){y_dy = ydy;}
      void set_x_pos(const float& xpos){x_pos = xpos;}
      void set_y_pos(const float& ypos){y_pos = ypos;}
      float get_x_pos(){return x_pos;}
      float get_y_pos(){return y_pos;}

      virtual bool LoadImg(const char * s , SDL_Renderer* screen);
      void Show(SDL_Renderer *des);
      void set_clips();
      void doPlayer(Map& map_data);
      void CheckToMap(Map& map_data);
      void Set_MapXY(int map_x_, int map_y_);
      int get_width_frame()const{return width_frame;}
      int get_height_frame()const{return height_frame;}

      void setAnimationPos(const int& pos_a_, const int &pos_b_){pos_a = pos_a_; pos_b = pos_b_ ;}
      void set_input_left(const int & ipleft){input_type.left_ = ipleft;}
      void ImMoveType(SDL_Renderer* des);
      void initThreat();







    private:

     float x_dx;
     float y_dy;
     float x_pos;
     float y_pos;
     int width_frame ;
     int height_frame ;
     SDL_Rect frame_clip[8];
     int frame;
     bool on_ground;
     int map_x_ , map_y_;
     int come_back_time;

     int pos_a;
     int pos_b;
     Input input_type;




};

#endif // THREATOBJECTS_H
