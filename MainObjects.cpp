#include "MainObjects.h"
using namespace std;
 MainObject :: MainObject(){
  frame = 0;
  x_pos =0;
  y_pos = 0;
  x_dx  = 0;
  y_dy = 0;
 width_frame = 0;
 height_frame = 0;
 status_move = -1;
 input_type.left_ =0;
 input_type.right_=0;
 input_type.up_=0;
 input_type.down_=0;
 input_type.jump_=0;
 on_ground = false;
 map_x_ =0;
 map_y_ =0;
come_back_time =0;





 }
 bool MainObject::LoadImg(const char*s,SDL_Renderer *screen){
   bool ret = objects::LoadImg(s,screen);
   if(ret == true){
     width_frame = rect.w/8;
     height_frame = rect.h;


   }

   return ret;

 }
void MainObject::set_clips()
{

   if(width_frame > 0 && height_frame > 0)
   {

       for(int i = 0 ; i < 8;i++){
       frame_clip[i].x=i*width_frame;
       frame_clip[i].y =0;
       frame_clip[i].w=width_frame;
       frame_clip[i].h=height_frame;


       }

   }

}
  void MainObject::Show(SDL_Renderer* des)
  {
      if(status_move == WALK_LEFT)
      {
         LoadImg("img\\player_left.png",des);

      }
      else{
        LoadImg("img\\player_right.png",des);

      }
      if(input_type.left_ == 1 || input_type.right_== 1)
      {
         frame++;
      }
      else
      {
       frame = 0;
      }
      if(frame >= 8){frame = 0;}
     if(come_back_time ==0 )
     {
         rect.x = x_pos - map_x_ ;
      rect.y = y_pos - map_y_ ;

      SDL_Rect * current_clip =&frame_clip[frame];
      SDL_Rect renderQuad ={rect.x,rect.y,width_frame,height_frame};
      SDL_RenderCopy(des,object, current_clip,&renderQuad );

     }

  }
    void MainObject :: HandleInputAction(SDL_Event events, SDL_Renderer* screen)
    {
        if(events.type == SDL_KEYDOWN)
        {
           switch(events.key.keysym.sym)
           {
                case SDLK_RIGHT:
                    {
                        status_move = WALK_RIGHT;
                        input_type.right_ = 1;
                        input_type.left_  = 0;


                    }
                    break;
                case SDLK_LEFT:
                    {
                        status_move = WALK_LEFT;
                        input_type.left_ = 1;
                        input_type.right_=0;


                    }
                    break;
                case SDLK_UP:
                    {
                       input_type.jump_ = 1;
                    }
                    break;

                case SDLK_SPACE:


           }
        }
          else if(events.type == SDL_KEYUP)
          {
                switch(events.key.keysym.sym)
           {
                case SDLK_RIGHT:
                    {

                        input_type.right_ = 0;


                    }
                    break;
                case SDLK_LEFT:
                    {

                        input_type.left_ = 0;

                    }
                    break;


           }



          }



     }

 void MainObject::doPlayer(Map& map_data)
 {
   if(come_back_time == 0)
   {
        x_dx =  0;
    y_dy += GRAVITY_SPEED;
    if(y_dy > MAX_FALL_SPEED){
        y_dy = MAX_FALL_SPEED;
    }
    if(input_type.left_ == 1)
    {
        x_dx -= PLAYER_SPEED;
    }
    if(input_type.right_ == 1)
    {
        x_dx += PLAYER_SPEED;
    }
    if(input_type.jump_ == 1)
    {
      if(on_ground == true)
         {
               y_dy = - 50 ;
         }
        on_ground = false;
        input_type.jump_=0;

    }

    CheckToMap(map_data);
    Set_Moving_Map(map_data);


   }
  if(come_back_time >0)
  {
     come_back_time --;
     if(come_back_time ==0)
     {
         if(x_pos > 256)
         {
             x_pos -= 128;
         }
           else
           {
               x_pos = 0;
           }

             y_pos = 0;
             x_dx=0;
             y_dy =0;
     }
  }

 }
void MainObject::CheckToMap(Map& map_data)
    {


        int x1 = 0;
        int x2 = 0;
        int y1 = 0;
        int y2 = 0;
        int height_min = (height_frame < TILE_SIZE)? height_frame : TILE_SIZE;
        x1 = (x_pos + x_dx)/TILE_SIZE;
        x2 = (x_pos + x_dx + width_frame -1)/TILE_SIZE;
        y1 = (y_pos)/TILE_SIZE;
        y2 = (y_pos + height_min -1)/TILE_SIZE;

        if(x1 >= 0 && x2 < MAX_MAP_X && y1 >=0 && y2 < MAX_MAP_Y)
        {
           if(x_dx > 0)
           {
               if(map_data.tile[y1][x2] != BLANK_TILE || map_data.tile[y2][x2]!= BLANK_TILE)
               {
                 x_pos = x2 * TILE_SIZE;
                 x_pos  -= width_frame +1;
                 x_dx  = 0;
               }
           }


           else if(x_dx < 0)
           {
                if(map_data.tile[y1][x1] != BLANK_TILE || map_data.tile[y2][x1]!= BLANK_TILE)
               {
                 x_pos = (x1 + 1 ) * TILE_SIZE;

                 x_dx  = 0;
               }


           }



        }


      int width_min = width_frame < TILE_SIZE ? width_frame : TILE_SIZE;
      x1 = (x_pos )/TILE_SIZE;
      x2 = (x_pos + width_min)/TILE_SIZE;
      y1 = (y_pos + y_dy)/TILE_SIZE;
      y2 = (y_pos + y_dy + height_frame - 1)/TILE_SIZE;

        if(x1 >=0 && x2 < MAX_MAP_X && y1 >=0 && y2 <= MAX_MAP_Y)
        {
           if(y_dy > 0)
           {
             if(map_data.tile[y2][x1] != BLANK_TILE || map_data.tile[y2][x2] != BLANK_TILE)
                {
                      y_pos = y2* TILE_SIZE;
                      y_pos -= (height_frame + 1);
                      y_dy = 0;
                      on_ground = true;

                }


           }
           else if( y_dy < 0){
               if(map_data.tile[y1][x1] != BLANK_TILE || map_data.tile[y1][x2] != BLANK_TILE)
                  {
                      y_pos = (y1 + 1)*TILE_SIZE;
                      y_dy  = 0;
                  }

           }
        }


       x_pos += x_dx;
       y_pos += y_dy;
       if(x_pos < 0)
       {
           x_pos=0;
       }
       else if(x_pos + width_frame > map_data.max_x)
       {
           x_pos = map_data.max_x - width_frame -1;

       }
       if(y_pos < 0)
       {
           y_pos=0;
       }
       if(y_pos >= map_data.max_y - 2 - TILE_SIZE)
       {
           come_back_time = 60;
       }




    }

void MainObject::Set_Moving_Map(Map &map_data)
 {
     map_data.start_x = x_pos - (SCREEN_WIDTH/2);
     if(map_data.start_x < 0)
     {
         map_data.start_x =0;
     }
     else if(map_data.start_x + SCREEN_WIDTH > map_data.max_x)
     {
         map_data.start_x = map_data.max_x - SCREEN_WIDTH;

     }
     map_data.start_y = y_pos - (SCREEN_HEIGHT/2);
     if(map_data.start_y < 0)
     {
         map_data.start_y =0;
     }
     else if(map_data.start_y + SCREEN_HEIGHT > map_data.max_y)
     {
         map_data.start_y = map_data.max_y - SCREEN_HEIGHT;

     }



 }

void MainObject::Set_MapXY(int moving_x, int moving_y)
  {

     map_x_ = moving_x;
     map_y_ = moving_y;



  }
