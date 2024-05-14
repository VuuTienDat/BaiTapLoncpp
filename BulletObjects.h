#ifndef BULLETOBJECTS_H
#define BULLETOBJECTS_H
#include "objects.h"
#include "defs.h"

class BulletObjects : public objects
  {
    public:
        BulletObjects();
        ~BulletObjects();
        enum BulletDir
        {
          DIR_RIGHT = 21,
          DIR_LEFT = 20,
        };
        virtual bool LoadImg(const char* s , SDL_Renderer* screen);
        void set_x_dx(const int& xdx){x_dx = xdx;}
        void set_y_dy(const int& ydy){y_dy = ydy;}
        int get_x_dx() const{return x_dx;}
        int get_y_dy() const {return y_dy;}
        void set_is_move(const bool& isMove){is_move = isMove;}
        bool Get_is_move() const {return is_move;}
        void set_bullet_dir(const int& bulletDir){bullet_dir = bulletDir;}
        int get_bullet_dir() const {return bullet_dir;}
        int get_width_frame(){return width_frame;}
        int get_height_frame(){return height_frame;}

        void HandleMove(const int& x_border, const int& y_border);
    private:
        int x_dx;
        int y_dy;
        bool is_move;
        int bullet_dir;
        int width_frame;
        int height_frame;




  };



#endif // BULLETOBJECTS_H
