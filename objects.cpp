#include "objects.h"
using namespace std;

bool objects::LoadImg(const char* s, SDL_Renderer* screen)
{
    Freedom();
    if (s == NULL)
    {
        SDL_Log("Khong co duong dan");
        return false;
    }


    SDL_Texture* new_texture= NULL;
    SDL_Surface* load_surface= IMG_Load(s);
    if(load_surface != NULL){

        new_texture = SDL_CreateTextureFromSurface(screen,load_surface);
        if(new_texture != NULL){
            rect.w = load_surface->w;
            rect.h = load_surface->h;
        }

        SDL_FreeSurface(load_surface);

    }
    object = new_texture;


    return object != NULL;

}

void objects::Render(SDL_Renderer *des, const SDL_Rect* clip){
  SDL_Rect renderquad = {rect.x, rect.y, rect.w,rect.h};
  SDL_RenderCopy(des,object,clip,&renderquad);

}
void objects::Freedom(){
  if(object !=NULL){
    SDL_DestroyTexture(object);
    object = NULL;
    rect.w = 0;
    rect.h=0;
  }
}


