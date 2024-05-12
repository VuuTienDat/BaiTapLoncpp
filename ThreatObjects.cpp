#include "ThreatObjects.h"

ThreatObjects::ThreatObjects()
{
     x_dx = 0 ;
     y_dy = 0 ;
     x_pos = 0;
     y_pos = 0;
     width_frame = 0 ;
     height_frame = 0 ;
     frame = 0;
     on_ground = false;
     map_x_ = 0 , map_y_ = 0;
     come_back_time = 0;


     pos_a = 0;
     pos_b = 0;
     input_type.left_ = 1;









}

ThreatObjects::~ThreatObjects()
{

}

bool ThreatObjects::LoadImg(const char* s, SDL_Renderer* screen)
{
    bool ret = objects :: LoadImg(s,screen);
    if(ret == true)
    {
      width_frame = rect.w/8;
      height_frame = rect.h;

    }
    else {SDL_Log("Khong khoi duoc nhan vat Threat \n");}
    return ret;
}

void ThreatObjects::Show(SDL_Renderer* des)
{
     if(come_back_time ==0)
     {

      rect.x = x_pos - map_x_ ;
      rect.y = y_pos ;

      frame ++;
      if(frame >= 8){frame =0;}
      SDL_Rect * current_clip =&frame_clip[frame];

      SDL_Rect renderQuad ={rect.x,rect.y,width_frame,height_frame};
      SDL_RenderCopy(des,object,current_clip,&renderQuad );


     }



}
void ThreatObjects::set_clips()
{
    if(width_frame > 0 && height_frame > 0)
    {
        for(int i = 0 ; i <8 ;i++)
    {
      frame_clip[i].x = i* width_frame;
      frame_clip[i].y = 0;
      frame_clip[i].w = width_frame;
      frame_clip[i].h = height_frame;



    }





    }


}

void ThreatObjects::doPlayer(Map& map_data)
{
    if(come_back_time ==0 )
    {
     y_dy += Threat_Gravity;


     CheckToMap(map_data);



        if(input_type.left_ == 1)
       {
           x_dx = -Threat_Velocity;
       }
       else if(input_type.right_ == 1)
       {
           x_dx = Threat_Velocity;
       }




    }
  else if(come_back_time > 0)
    {
       come_back_time--;
       if(come_back_time == 0 )
       {
         initThreat();
       }
    }




}

void ThreatObjects::CheckToMap(Map& map_data)
{




      int  x1 = (x_pos + x_dx)/TILE_SIZE;
      int  x2 = (x_pos + x_dx + width_frame )/TILE_SIZE;
      int  y1 = (y_pos)/TILE_SIZE;
      int  y2 = (y_pos + height_frame)/TILE_SIZE;

        if(x1 >= 0 && x2 < MAX_MAP_X && y1 >=0 && y2 < MAX_MAP_Y)
        {
           if(x_dx > 0)
           {
                   int val1 = map_data.tile[y1][x2];
                   int val2 = map_data.tile[y2][x2];




                  if((val1 != BLANK_TILE && val1 != MONEY) || (val2!= BLANK_TILE && val2 != MONEY))
                   {
                     x_pos = x2 * TILE_SIZE;
                     x_pos  -= width_frame +1;
                     x_dx  = 0;

                      if(input_type.right_ == 1)
                        pos_b = x_pos-2;
                        pos_a = x_pos-300;


                   }




           }


           else if(x_dx < 0)
           {
              int val1 = map_data.tile[y1][x1];
              int val2 = map_data.tile[y2][x1];
                if((val1 != BLANK_TILE && val1 != MONEY) || (val2 != BLANK_TILE && val2 != MONEY))
               {
                 x_pos = (x1 + 1 ) * TILE_SIZE;

                 x_dx  = 0;

                      if(input_type.left_ == 1)
                        pos_a = x_pos+2;
                        pos_b = x_pos+300;



               }



           }
        }



      x1 = (x_pos )/TILE_SIZE;
      x2 = (x_pos + width_frame)/TILE_SIZE;
      y1 = (y_pos + y_dy)/TILE_SIZE;
      y2 = (y_pos + y_dy + height_frame )/TILE_SIZE;

        if(x1 >=0 && x2 < MAX_MAP_X && y1 >=0 && y2 <= MAX_MAP_Y)
        {
           if(y_dy > 0)
           {
             int val1 = map_data.tile[y2][x1];
             int val2 = map_data.tile[y2][x2];
               if((val1!= BLANK_TILE && val1 != MONEY) || (val2!= BLANK_TILE && val2 != MONEY))
                {
                      y_pos = y2* TILE_SIZE;
                      y_pos -= (height_frame + 1);
                      y_dy = 0;
                      on_ground = true;

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
        if(y_pos >= map_data.max_y - 2 - TILE_SIZE)
       {
           come_back_time = 1;


       }





    }

}

void ThreatObjects::Set_MapXY(int map_x)
{
    map_x_ = map_x;

}
void ThreatObjects::ImMoveType(SDL_Renderer* des)
{


       if(on_ground == true)
       {
          if(x_pos > pos_b)
          {
             input_type.left_ = 1;
             input_type.right_ = 0;
             LoadImg("img\\threat_left.png",des);
             set_clips();


          }
          else if(x_pos < pos_a)
          {
            input_type.left_ = 0;
             input_type.right_ = 1;
             LoadImg("img\\threat_right.png",des);
             set_clips();


          }


       }
       else
       {
         if(input_type.left_ == 1)
         {
            LoadImg("img\\threat_left.png",des);
         }
       }

}
void ThreatObjects::initThreat()
{
    x_dx=0;
    y_dy=0;



        if(x_pos  > 256)
            {
                x_pos -= 128;
                pos_a -= 128;
                pos_b -= 128;

            }
            else
            {
               x_pos =0;

            }









     y_pos = 0;


}


