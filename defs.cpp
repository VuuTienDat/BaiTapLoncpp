#include "defs.h"
using namespace std;


bool Check_Crash(const SDL_Rect &object1 ,const SDL_Rect &object2)
{

int left_a = object1.x;
int right_a = object1.x + object1.w;
int top_a = object1.y;
int bottom_a = object1.y + object1.w;

int left_b = object2.x;
int right_b = object2.x + object2.w;
int top_b = object2.y;
int bottom_b = object2.y + object2.h;
// size_a < size_b(vien dan < nhan vat)
//
if(left_a > left_b && left_a < right_b)
    {
        if(top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }
if(left_a > left_b && left_a < right_b)
    {
        if(bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }
if(right_a > left_b && right_a < right_b)
    {
        if(top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }
if(right_a > left_b && right_a < right_b)
    {
        if(bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }
// size a > size_b (nhan vat va threat)

if(left_b > left_a && left_b < right_a)
    {
        if(top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }
if(left_b > left_a && left_b < right_a)
    {
        if(bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }
if(right_b > left_a && right_b < right_a)
    {
        if(top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }
if(right_a > left_b && right_a < right_b)
    {
        if(bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }


 return false;
}


 TTF_Font* loadFont(const char* path, int size)
    {
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load font %s", TTF_GetError());
        }
        return gFont;
    }

    SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor,SDL_Renderer* des)
    {
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, text, textColor );
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface( des, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
        }

        SDL_FreeSurface( textSurface );
        return texture;
    }




    Mix_Music *loadMusic(const char* path)
    {
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                           "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }
    void play_Music(Mix_Music *gMusic ,int check_)
    {

                if (gMusic == nullptr) return;
             Mix_VolumeMusic(MIX_MAX_VOLUME/5);
         if(check_ == Turn_on)
            {
                if(Mix_PausedMusic() == 1 || Mix_PlayingMusic() == 0)
                {
                    Mix_PlayMusic(gMusic,-1);
                }




            }
        else if(check_ == Turn_off)
        {
            Mix_PauseMusic();
        }




    }

    Mix_Chunk* loadSound(const char* path) {
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
    }
    void play_Chunk(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {

            Mix_PlayChannel( -1, gChunk, 0 );
            Mix_VolumeChunk(gChunk,MIX_MAX_VOLUME);
        }
    }


 bool Check_Focus_With_Rect(const SDL_Rect& rect, const int& x, const int& y)
{
    int posx1 = rect.x;
    int posx2 = rect.x + rect.w;
    int posy1 = rect.y;
    int posy2 = rect.y + rect.h;
    return x>=posx1 && x<=posx2&& y >= posy1 && y <= posy2;

}















