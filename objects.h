#ifndef OBJECTS_H
#define OBJECTS_H
#include "defs.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace std;
class objects
{
   public:
  objects(){
   object = NULL;
   rect.x = 0;
   rect.y = 0;
   rect.w = 0;
   rect.h = 0;
   }
   void Set_Rect(const int& x, const int & y)
   {
       rect.x = x;
       rect.y= y;

   }
  SDL_Rect get_rect(){return rect;}
  bool LoadImg(const char*s,SDL_Renderer *screen);
  void  Render(SDL_Renderer *des, const SDL_Rect* clip = NULL);
  void Freedom();

  ~objects(){Freedom();}
   protected :

   SDL_Texture* object;
   SDL_Rect rect;


};


#endif
