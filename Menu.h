#include "defs.h"
#include "SDL_ttf.h"
#include <string>
using namespace std;

class Menu
  {

 public:
    Menu();
    ~Menu();


    bool load_Img(const char*s , SDL_Renderer* des);
    void show(SDL_Renderer * des);
    void HanldeInputAction1(SDL_Event , int , int , int&);
    void HanldeInputAction2(SDL_Event , int , int ,int&);
    void Show_Menu(SDL_Renderer *des);
    void Set_Render_Text(const char* text,const SDL_Rect&, TTF_Font* font, SDL_Renderer* des,SDL_Color);
    void Set_Rect_Coordinate(SDL_Rect& , int x, int y);
    void Set_Rect_Text(SDL_Rect& rect_,const char* text_font ,TTF_Font* font ,SDL_Renderer* des);
    void free();

    bool Check_Focus_With_Rect(const SDL_Rect&, const int& , const int& );
    bool set_change_color(bool change, int x){check_click[x] = change;}
    SDL_Rect get_rect_text(int x){return text_ord[x];}
    int check_music_(){return check_music;}
    void Show_EndGame(SDL_Renderer* des);

    void Show_Win(SDL_Renderer *des);
    void set_music(){check_music = Turn_off;}







 private:
     SDL_Rect text_ord[8];
     string text_ff[8];
    SDL_Texture* obj;
    SDL_Color color1 ,color2,color_win,color_lose;
    bool Change_color ;
    int check_music;
    bool check_click[8];
    Mix_Chunk* ring = nullptr;
    TTF_Font* font1 =nullptr;
    TTF_Font* font2 = nullptr;










  };
