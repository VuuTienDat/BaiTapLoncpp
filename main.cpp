#include "set_up_loop.h"
int main(int argc, char *argv[])
{
   Loop_ loop;
   loop.InitData();
   loop.play_game_happy();
   loop.Free();
    return 0;
}
