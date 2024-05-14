#include "BulletObjects.h"
#include "objects.h"
BulletObjects::BulletObjects()
{
    x_dx = 0;
    y_dy = 0;
    is_move = false;


}

BulletObjects::~BulletObjects()
{
    Freedom();
}
bool BulletObjects::LoadImg(const char* s , SDL_Renderer* screen)
  {
         bool ret = objects::LoadImg(s,screen);
   if(ret == true){
     width_frame = rect.w;
     height_frame = rect.h;


   }

   return ret;

  }


void BulletObjects::HandleMove(const int& x_border , const int& y_border)
{
   if(bullet_dir == DIR_LEFT)
   {
       rect.x -= x_dx;
       if(rect.x < x_border){is_move = false;}
   }
   else
   {
       rect.x += x_dx;
       if(rect.x > x_border){is_move = false;}
   }



}
