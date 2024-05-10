#ifndef GRAPHIC__H
#define GRAPHIC__H
#include "defs.h"

class graphic_
{
    public:
        graphic_();
       ~graphic_();
     void Show_(SDL_Renderer *des,int& , int& );
     SDL_Texture* loadImg(const char* s,SDL_Rect&, SDL_Renderer* );
     void Set_Rect_Text(SDL_Rect& rect_,int x ,TTF_Font* font ,SDL_Renderer* des);
     void Set_Render_Text(int x,const SDL_Rect&, TTF_Font* font, SDL_Renderer* des,SDL_Color);
     void free();
     void set_up(SDL_Renderer* );



    private:
        SDL_Rect heart;
        SDL_Rect coins;
        SDL_Rect back_ground;
        SDL_Rect index_heart;
        SDL_Rect index_coins;


        SDL_Texture* Heart = nullptr;
        SDL_Texture* Coins = nullptr;
        SDL_Texture* Back_ground = nullptr;
        TTF_Font *font_1 = nullptr;
        SDL_Color color1;

};

#endif // GRAPHIC__H
