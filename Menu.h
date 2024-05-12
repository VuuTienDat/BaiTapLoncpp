#include "defs.h"
#include "SDL_ttf.h"
#include <string>
using namespace std;

class Menu
  {

 public:
    Menu();
    ~Menu();


    SDL_Texture* loadImg(const char* s,SDL_Rect& rect, SDL_Renderer* des);

    void HanldeInputAction1(SDL_Event , int , int , int&);
    void HanldeInputAction2(SDL_Event , int , int ,int&);
    void HanldeInputAction3(SDL_Event , int , int ,int&);


    void Show_Menu(SDL_Renderer *des);
    void Set_Render_Text(const char* text, SDL_Rect&, TTF_Font* font, SDL_Renderer* des,SDL_Color);
    void Set_Rect_Coordinate(SDL_Rect& , int x, int y);

    void free();


    bool set_change_color(bool change, int x){check_click[x] = change;}

    int check_music_(){return check_music;}
    void Show_EndGame(SDL_Renderer* des,const int&);

    void Show_Win(SDL_Renderer *des,const int&);
    void Set_Render_Text_Number(SDL_Rect& rect_,const int& x ,TTF_Font* font ,SDL_Renderer* des);
    void Set_Menu(SDL_Renderer*);
    void Show_Continue(SDL_Renderer* des);

    void set_up_Menu();






 private:
     SDL_Rect text_ord[11];

     SDL_Rect index_mark;
     SDL_Rect background;



     string text_ff[11];

    SDL_Texture* back_ground;
    SDL_Texture* back_win;
    SDL_Texture* back_lose;



    SDL_Texture* background_again;




    SDL_Color color1 ,color2,color_win,color_lose;
    bool Change_color ;
    int check_music;
    bool check_click[8];
    Mix_Chunk* ring = nullptr;
    TTF_Font* font1 =nullptr;
    TTF_Font* font2 = nullptr;












  };
