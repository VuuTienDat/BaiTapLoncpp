#ifndef BULLETOBJECTS_H
#define BULLETOBJECTS_H


class BulletObjects : public objects
{
    public:
        BulletObjects();
        ~BulletObjects();
        void set_x_dx(const int& xdx){x_dx = xdx;}
        void set_y_dy(const int& ydy){y_dy = ydy;}
        void set_is_move(bool &isMove){is_move = isMove;}
        void HandleMove(const int& x_border, const int& y_border);
    public:
        int x_dx;
        int y_dy;
        bool is_move;



};

#endif // BULLETOBJECTS_H
