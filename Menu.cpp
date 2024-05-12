#include "Menu.h"
Menu::Menu()
{
}

Menu::~Menu()
{

     Mix_FreeChunk(ring);
     ring = nullptr;
     TTF_CloseFont(font1);
     font1 = nullptr;
     TTF_CloseFont(font2);
     font2 = nullptr;
     SDL_DestroyTexture(back_ground);
     SDL_DestroyTexture(background_again);

     SDL_DestroyTexture(back_lose);
     SDL_DestroyTexture(back_win);
     back_ground = nullptr;
     background_again = nullptr;

     back_lose = nullptr;
     back_win = nullptr;



}

SDL_Texture* Menu::loadImg(const char* s,SDL_Rect& rect, SDL_Renderer* des)
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



void Menu::HanldeInputAction1(SDL_Event event,int x , int y , int& status)
{

    if(Check_Focus_With_Rect(text_ord[Play_Game],x,y))
    {

     set_change_color(true,Play_Game);
      if(event.type == SDL_MOUSEBUTTONDOWN){  status = PLAY_GAME;}
    }
     else {set_change_color(false,Play_Game); }


     if(Check_Focus_With_Rect(text_ord[Exit_Game],x,y))
    {

     set_change_color(true,Exit_Game);
      if(event.type == SDL_MOUSEBUTTONDOWN){  status = EXIT_GAME_;}
    }
     else {set_change_color(false,Exit_Game); }

   if(check_music == Turn_off)
   {

      if(Check_Focus_With_Rect(text_ord[On],x,y))
    {

     set_change_color(true,On);
      if(event.type == SDL_MOUSEBUTTONDOWN){  play_Chunk(ring);check_music = Turn_on;  }
    }
     else {set_change_color(false,On); }



   }

  else if(check_music == Turn_on)
    {
          if(Check_Focus_With_Rect(text_ord[Off],x,y))
    {

     set_change_color(true,Off);
      if(event.type == SDL_MOUSEBUTTONDOWN){ play_Chunk(ring);check_music = Turn_off;}
    }
     else {set_change_color(false,Off); }



    }



}

  void Menu::HanldeInputAction2(SDL_Event event, int x, int y, int& status)
  {
     if(Check_Focus_With_Rect(text_ord[Play_Again],x,y))
    {
        play_Chunk(ring);
     set_change_color(true,Play_Again);
      if(event.type == SDL_MOUSEBUTTONDOWN){ status = SHOW_MENU;}
    }
     else {set_change_color(false,Play_Again); }

       if(Check_Focus_With_Rect(text_ord[Exit_Game],x,y))
    {
        play_Chunk(ring);
     set_change_color(true,Exit_Game);
      if(event.type == SDL_MOUSEBUTTONDOWN){ status = EXIT_GAME_;}
    }
     else {set_change_color(false,Exit_Game); }



  }
void Menu::HanldeInputAction3(SDL_Event event, int x, int y, int& status)
  {


       if(Check_Focus_With_Rect(text_ord[Back],x,y))
        {

         set_change_color(true,Back);
          if(event.type == SDL_MOUSEBUTTONDOWN){ status = SHOW_MENU;}
        }
            else {set_change_color(false,Back); }

     if(Check_Focus_With_Rect(text_ord[Continue],x,y))
        {

         set_change_color(true,Continue);
          if(event.type == SDL_MOUSEBUTTONDOWN){ status = PLAY_GAME;}
        }
        else {set_change_color(false,Continue); }



  }






void Menu::free()
{

}
void Menu::Show_Menu(SDL_Renderer* des)
{


    SDL_RenderCopy(des,back_ground,NULL,NULL);


    for(int i =0 ; i <= 2 ; i++)
    {


        Set_Rect_Coordinate(text_ord[i], 480, 150 + text_ord[i].h *i );
     if(check_click[i] == false)
     {
        Set_Render_Text(text_ff[i].c_str(),text_ord[i],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[i].c_str(),text_ord[i],font1,des,color2);

      }

    }
    if(check_music == Turn_off)
    {

            Set_Rect_Coordinate(text_ord[On], 480, 150 + text_ord[On].h *3 );
         if(check_click[On] == false)
         {
            Set_Render_Text(text_ff[On].c_str(),text_ord[On],font1,des,color1);
         }
          else{

            Set_Render_Text(text_ff[On].c_str(),text_ord[On],font1,des,color2);
        }
    }
    else if(check_music == Turn_on)
    {

            Set_Rect_Coordinate(text_ord[Off], 480, 150 + text_ord[Off].h *3 );
         if(check_click[Off] == false)
         {
            Set_Render_Text(text_ff[Off].c_str(),text_ord[Off],font1,des,color1);
         }
          else{

            Set_Render_Text(text_ff[Off].c_str(),text_ord[Off],font1,des,color2);
        }
    }



}

void Menu::Set_Render_Text(const char* text, SDL_Rect&rect, TTF_Font* font, SDL_Renderer* des,SDL_Color color )
{

       SDL_Surface* textSurface = TTF_RenderText_Solid( font, text,color );
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return ;
        }
        rect.w = textSurface->w;
        rect.h = textSurface->h;
        SDL_Texture* texture = SDL_CreateTextureFromSurface( des, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
        }




         SDL_RenderCopy(des,texture,NULL,&rect);
         SDL_FreeSurface( textSurface );
         SDL_DestroyTexture(texture);






}


void Menu::Set_Rect_Coordinate(SDL_Rect& rect,int x, int y)
{
    rect.x = x;
    rect.y =y;
}


void Menu::Show_EndGame(SDL_Renderer* des,const int &x)
{


    SDL_RenderCopy(des,back_lose,NULL,NULL);



    Set_Rect_Coordinate(text_ord[Loser], 475, 100 );
    Set_Render_Text(text_ff[Loser].c_str(),text_ord[Loser],font2,des,color_lose);



    Set_Render_Text(text_ff[Mark_index].c_str(),text_ord[Mark_index],font2,des,color_win);

    Set_Render_Text_Number(index_mark,x,font2,des);



    Set_Rect_Coordinate(text_ord[Play_Again], 480, 240 );
    if(check_click[Play_Again] == false)
     {
        Set_Render_Text(text_ff[Play_Again].c_str(),text_ord[Play_Again],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Play_Again].c_str(),text_ord[Play_Again],font1,des,color2);

      }


    Set_Rect_Coordinate(text_ord[Exit_Game], 480, 300);
    if(check_click[Exit_Game] == false)
     {
        Set_Render_Text(text_ff[Exit_Game].c_str(),text_ord[Exit_Game],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Exit_Game].c_str(),text_ord[Exit_Game],font1,des,color2);

      }
}

void Menu::Show_Win(SDL_Renderer* des,const int& x)
{


    SDL_RenderCopy(des,back_win,NULL,NULL);

    Set_Rect_Coordinate(text_ord[Win_Game], 480, 100 );
    Set_Render_Text(text_ff[Win_Game].c_str(),text_ord[Win_Game],font2,des,color_win);


    Set_Render_Text(text_ff[Mark_index].c_str(),text_ord[Mark_index],font2,des,color_win);

    Set_Render_Text_Number(index_mark,x,font2,des);



    Set_Rect_Coordinate(text_ord[Play_Again], 480, 240 );
    if(check_click[Play_Again] == false)
     {
        Set_Render_Text(text_ff[Play_Again].c_str(),text_ord[Play_Again],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Play_Again].c_str(),text_ord[Play_Again],font1,des,color2);

      }


    Set_Rect_Coordinate(text_ord[Exit_Game], 480, 300);
    if(check_click[Exit_Game] == false)
     {
        Set_Render_Text(text_ff[Exit_Game].c_str(),text_ord[Exit_Game],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Exit_Game].c_str(),text_ord[Exit_Game],font1,des,color2);

      }




}


void Menu::Set_Render_Text_Number(SDL_Rect& rect_,const int& x, TTF_Font* font, SDL_Renderer* des)
{
       string m = to_string(x);

       SDL_Surface* textSurface = TTF_RenderText_Solid( font, m.c_str(),color_win);
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return ;
        }
        rect_.w = textSurface->w;
        rect_.h = textSurface->h;
        SDL_Texture* texture = SDL_CreateTextureFromSurface( des, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
            return ;
        }




         SDL_RenderCopy(des,texture,NULL,&rect_);
         SDL_FreeSurface( textSurface );
         SDL_DestroyTexture(texture);

}


void Menu::Show_Continue(SDL_Renderer* des)
{

     SDL_RenderCopy(des,background_again,NULL,NULL);


        Set_Rect_Coordinate(text_ord[Back], 480, 250);
    if(check_click[Back] == false)
     {
        Set_Render_Text(text_ff[Back].c_str(),text_ord[Back],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Back].c_str(),text_ord[Back],font1,des,color2);

      }

        Set_Rect_Coordinate(text_ord[Continue], 480, 320);
    if(check_click[Continue] == false)
     {
        Set_Render_Text(text_ff[Continue].c_str(),text_ord[Continue],font1,des,color1);
     }
      else{

        Set_Render_Text(text_ff[Continue].c_str(),text_ord[Continue],font1,des,color2);

      }





}
void Menu :: Set_Menu(SDL_Renderer* des)
 {
     back_ground= loadImg("img\\back_menu.jpg", background, des);
     back_lose=loadImg("img\\back_lose.jpg",background,des);
     back_win =loadImg("img\\back_win.jpg",background,des);

     background_again = loadImg("img\\back_continue.jpg",background,des);

 }

void Menu::set_up_Menu()
  {

         for(int i = 0 ; i < 6 ; i++)
    {
        text_ord[i] ={0,0,0,0};
        check_click[i] = false;

    }
    check_click[9] = false,check_click[10] = false;
    text_ff[0] = "Play Game";
    text_ff[1] = "Exit";
    text_ff[2] = "Sound Mode";
    text_ff[3] = "On";
    text_ff[4] = "Off";
    text_ff[5] = "Play Again";
    text_ff[6] = "You Win";
    text_ff[7] = "You Lose";
    text_ff[8] = "Mark: ";
    text_ff[9] ="Continue";
    text_ff[10] = "Back";

    color1 ={255,255,70,255};
    color2 ={0 ,255, 255,255};
    color_win={255,127,39,255};
    color_lose={0,255,0,255};
    Change_color = false;
    check_music = Turn_off;
    ring = loadSound("music\\beep_1.mp3");
    font1 = loadFont("Font\\extra.ttf",60);
    font2 = loadFont("Font\\extra.ttf",100);


    index_mark={810,400,0,0};
    text_ord[Mark_index]={480,400,0,0};
    background ={0,0,1280,640};


  }
