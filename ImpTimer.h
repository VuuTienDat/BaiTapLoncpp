#ifndef IMPTIMER_H
#define IMPTIMER_H
#include <SDL.h>
#include <SDL_image.h>

class ImpTimer
{
    public:
        ImpTimer();
         ~ImpTimer();
    void start();
    int get_ticks();

    private:
        int start_tick_;
        bool is_started_;




};

#endif // IMPTIMER_H
