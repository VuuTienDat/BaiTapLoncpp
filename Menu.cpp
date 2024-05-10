#include "Menu.h"
Menu::Menu()
{
    for(int i = 0 ; i < 6 ; i++)
    {
        text_ord[i] ={0,0,0,0};
        check_click[i] = false;

    }
    text_ff[0] = "Play Game";
    text_ff[1] = "Exit";
    text_ff[2] = "Sound Mode";
    text_ff[3] = "On";
    text_ff[4] = "Off";
    text_ff[5] = "Play Again";
    text_ff[6] = "You Win";
    text_ff[7] = "You Lose";
    color1 ={255,255,70,255};
    color2 ={0 ,255, 255,255};
    color_win={255,0,0,255};
    color_lose={0,0,0,255};
    Change_color = false;
    check_music = Turn_off;
    ring = loadSound("music\\beep_1.mp3");
    font1 = loadFont("Font\\extra.ttf",60);
    font2 = loadFont("Font\\extra.ttf",100);

}

Menu::~Menu()
{
     Mix_FreeChunk(ring);
     ring = nullptr;
     TTF_CloseFont(font1);
     font1 = nullptr;
     TTF_CloseFont(font2);
     font2 = nullptr;
}

bool Menu::load_Img(const char* s, SDL_Renderer* des)
{
    free();
    obj = IMG_LoadTexture(des,s);
    if(obj != NULL){
        return true;
    }
    return false;
}

void Menu::show(SDL_Renderer* des)
{

}

void Menu::HanldeInputAction1(SDL_Event event,int x , int y , int& n)
{

    if(Check_Focus_With_Rect(text_ord[Play_Game],x,y))
    {
     play_Chunk(ring);
     set_change_color(true,Play_Game);
      if(event.type == SDL_MOUSEBUTTONDOWN){ play_Chunk(ring); n = 4;}
    }
     else {set_change_color(false,Play_Game); }


     if(Check_Focus_With_Rect(text_ord[Exit_Game],x,y))
    {
    play_Chunk(ring);
     set_change_color(true,Exit_Game);
      if(event.type == SDL_MOUSEBUTTONDOWN){  n = 3;}
    }
     else {set_change_color(false,Exit_Game); }


      if(Check_Focus_With_Rect(text_ord[On],x,y))
    {

     set_change_color(true,On);
      if(event.type == SDL_MOUSEBUTTONDOWN){  play_Chunk(ring);check_music = Turn_on;  }
    }
     else {set_change_color(false,On); }


      if(Check_Focus_With_Rect(text_ord[Off],x,y))
    {

     set_change_color(true,Off);
      if(event.type == SDL_MOUSEBUTTONDOWN){ play_Chunk(ring);check_music = Turn_off;}
    }
     else {set_change_color(false,Off); }



}

  void Menu::HanldeInputAction2(SDL_Event event, int x, int y, int& n)
  {
     if(Check_Focus_With_Rect(text_ord[Play_Again],x,y))
    {
        play_Chunk(ring);
     set_change_color(true,Play_Again);
      if(event.type == SDL_MOUSEBUTTONDOWN){ n = 2;}
    }
     else {set_change_color(false,Play_Again); }

       if(Check_Focus_With_Rect(text_ord[Exit_Game],x,y))
    {
        play_Chunk(ring);
     set_change_color(true,Exit_Game);
      if(event.type == SDL_MOUSEBUTTONDOWN){ n = 3;}
    }
     else {set_change_color(false,Exit_Game); }



  }




void Menu::free()
{
    if(obj != NULL)
    {
        SDL_DestroyTexture(obj);
        obj = nullptr;


    }
}
void Menu::Show_Menu(SDL_Renderer* des)
{
    SDL_RenderCopy(des,obj,NULL,NULL);


    for(int i =0 ; i <= 4 ; i++)
    {
        Set_Rect_Text(text_ord[i],text_ff[i].c_str(),font1,des);

        Set_Rect_Coordinate(text_ord[i], 480, 150 + text_ord[i].h *i );
     if(check_click[i] == false)
     {
        Set_Render_Text(text_ff[i].c_str(),text_ord[i],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[i].c_str(),text_ord[i],font1,des,color2);

      }

    }





}

void Menu::Set_Render_Text(const char* text,const SDL_Rect&rect, TTF_Font* font, SDL_Renderer* des,SDL_Color color )
{

       SDL_Surface* textSurface = TTF_RenderText_Solid( font, text,color );
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return ;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface( des, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
        }




         SDL_RenderCopy(des,texture,NULL,&rect);
         SDL_FreeSurface( textSurface );
         SDL_DestroyTexture(texture);






}

void Menu::Set_Rect_Text(SDL_Rect& text_, const char* text_font, TTF_Font* font ,SDL_Renderer* des)
{  SDL_Color color = {255,0,0,255};
   SDL_Surface* surface_text = TTF_RenderText_Solid(font,text_font,color);
   if(surface_text == nullptr){SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,"Loi %s \n", IMG_GetError() );return ;}
   text_.w = surface_text->w;
   text_.h = surface_text->h;

   SDL_FreeSurface(surface_text);


}
void Menu::Set_Rect_Coordinate(SDL_Rect& rect,int x, int y)
{
    rect.x = x;
    rect.y =y;
}

bool Menu::Check_Focus_With_Rect(const SDL_Rect& rect, const int& x, const int& y)
{
    int posx1 = rect.x;
    int posx2 = rect.x + rect.w;
    int posy1 = rect.y;
    int posy2 = rect.y + rect.h;
    return x>=posx1 && x<=posx2&& y >= posy1 && y <= posy2;

}
void Menu::Show_EndGame(SDL_Renderer* des)
{

    SDL_RenderCopy(des,obj,NULL,NULL);


    Set_Rect_Text(text_ord[Loser],text_ff[Loser].c_str(),font2,des);
    Set_Rect_Coordinate(text_ord[Loser], 475, 100 );
    Set_Render_Text(text_ff[Loser].c_str(),text_ord[Loser],font2,des,color_lose);


    Set_Rect_Text(text_ord[Play_Again],text_ff[Play_Again].c_str(),font1,des);
    Set_Rect_Coordinate(text_ord[Play_Again], 480, 240 );
    if(check_click[Play_Again] == false)
     {
        Set_Render_Text(text_ff[Play_Again].c_str(),text_ord[Play_Again],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Play_Again].c_str(),text_ord[Play_Again],font1,des,color2);

      }

    Set_Rect_Text(text_ord[Exit_Game],text_ff[Exit_Game].c_str(),font1,des);
    Set_Rect_Coordinate(text_ord[Exit_Game], 480, 300);
    if(check_click[Exit_Game] == false)
     {
        Set_Render_Text(text_ff[Exit_Game].c_str(),text_ord[Exit_Game],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Exit_Game].c_str(),text_ord[Exit_Game],font1,des,color2);

      }
}

void Menu::Show_Win(SDL_Renderer* des)
{

    SDL_RenderCopy(des,obj,NULL,NULL);
    Set_Rect_Text(text_ord[Win_Game],text_ff[Win_Game].c_str(),font2,des);
    Set_Rect_Coordinate(text_ord[Win_Game], 450, 100 );
    Set_Render_Text(text_ff[Win_Game].c_str(),text_ord[Win_Game],font2,des,color_win);


    Set_Rect_Text(text_ord[Play_Again],text_ff[Play_Again].c_str(),font1,des);
    Set_Rect_Coordinate(text_ord[Play_Again], 480, 240 );
    if(check_click[Play_Again] == false)
     {
        Set_Render_Text(text_ff[Play_Again].c_str(),text_ord[Play_Again],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Play_Again].c_str(),text_ord[Play_Again],font1,des,color2);

      }

    Set_Rect_Text(text_ord[Exit_Game],text_ff[Exit_Game].c_str(),font1,des);
    Set_Rect_Coordinate(text_ord[Exit_Game], 480, 300);
    if(check_click[Exit_Game] == false)
     {
        Set_Render_Text(text_ff[Exit_Game].c_str(),text_ord[Exit_Game],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Exit_Game].c_str(),text_ord[Exit_Game],font1,des,color2);

      }




}
