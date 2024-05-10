#include "graphic_.h"
#include <string>
using namespace std;
graphic_::graphic_()
{
   heart = {64,4,0,0};
   coins = {640,4,0,0};
   marks = {200,0,0,0};

   font_1 =  loadFont("Font\\extra.ttf",30);
   color1 ={255,255,0,255};
   color2 = {255,255,255,255};
   index_heart = {100,0,0,0};
   index_coins={680,0,0,0};
   index_marks = {300,0,0,0};




}

graphic_::~graphic_()
{

    free();

}
void graphic_::Show_(SDL_Renderer* des,int& hearts_, int& coins_, int& mark)
{

  SDL_RenderCopy(des,Heart,NULL,&heart);
  SDL_RenderCopy(des,Coins,NULL,&coins);
  SDL_RenderCopy(des,Mark_,NULL,&marks);


  Set_Render_Text(hearts_,index_heart,font_1,des,color1);

  Set_Render_Text(coins_,index_coins,font_1,des,color1);

  Set_Render_Text(mark,index_marks,font_1,des,color1);



}

SDL_Texture* graphic_::loadImg(const char* s,SDL_Rect& rect, SDL_Renderer* des)
{

    SDL_Surface* img = IMG_Load(s);
    if(img == nullptr ){SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR,"Loi khoi tao %s\n",IMG_GetError()); return nullptr;}
    rect.w = img->w;
    rect.h = img->h;
    SDL_Texture* obj = SDL_CreateTextureFromSurface(des,img);
    if(obj == nullptr){SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR,"Loi khoi tao %s\n",SDL_GetError()); return nullptr; }
    SDL_FreeSurface(img);

    return obj;
}


void graphic_::Set_Render_Text(int x,  SDL_Rect& rect, TTF_Font* font, SDL_Renderer* des, SDL_Color color)
{
       string m = to_string(x);

       SDL_Surface* textSurface = TTF_RenderText_Solid( font, m.c_str(),color);
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return ;
        }
        rect.w = textSurface->w;
        rect.h = textSurface->h;
        SDL_Texture* texture = SDL_CreateTextureFromSurface( des, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
            return ;
        }




         SDL_RenderCopy(des,texture,NULL,&rect);
         SDL_FreeSurface( textSurface );
         SDL_DestroyTexture(texture);

}

void graphic_::set_up(SDL_Renderer* des)
{
    Heart = loadImg("img\\Heart.png",heart,des);
    Coins = loadImg("img\\coins.png",coins,des);

    SDL_Surface* textSurface = TTF_RenderText_Solid( font_1,"Mark" , color2 );
    if( textSurface == nullptr ) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
        return ;
    }
    marks.w = textSurface->w;
    marks.h = textSurface->h;
    Mark_ = SDL_CreateTextureFromSurface( des, textSurface );
    if( Mark_ == nullptr ) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
    }

    SDL_FreeSurface( textSurface );




}


void graphic_::free()
{
    if(Heart != nullptr)
    {
        SDL_DestroyTexture(Heart);
        Heart = nullptr;
    }
    if(Coins != nullptr)
    {
        SDL_DestroyTexture(Coins);
        Coins = nullptr;
    }

    if(Mark_ != nullptr)
    {
        SDL_DestroyTexture(Mark_);
        Mark_ = nullptr;
    }
   TTF_CloseFont(font_1);
   font_1 =nullptr;

}
