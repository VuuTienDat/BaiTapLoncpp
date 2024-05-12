#ifndef GRAPHIC__H
#define GRAPHIC__H
#include "defs.h"

class graphic_
{
    public:
        graphic_();
       ~graphic_();
     void Show_(SDL_Renderer *des,int& , int&, int& );
     SDL_Texture* loadImg(const char* s,SDL_Rect&, SDL_Renderer* );

     void Set_Render_Text(int x, SDL_Rect&, TTF_Font* font, SDL_Renderer* des,SDL_Color);
     void free();
     void set_up(SDL_Renderer* );

     void Show_Pause_Button(SDL_Renderer* , SDL_Event, int , int , int& );



    private:
        SDL_Rect heart;
        SDL_Rect coins;
        SDL_Rect marks;
         SDL_Rect pause;

        SDL_Rect index_heart;
        SDL_Rect index_coins;
        SDL_Rect index_marks;


        SDL_Texture* Heart = nullptr;
        SDL_Texture* Coins = nullptr;
        SDL_Texture* Back_ground = nullptr;
        SDL_Texture* Mark_ = nullptr;
        SDL_Texture* paused_button_black;
        SDL_Texture* paused_button_red;
        TTF_Font *font_1 = nullptr;
        SDL_Color color1;
        SDL_Color color2;

};

#endif // GRAPHIC__H
