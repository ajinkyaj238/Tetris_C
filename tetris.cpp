#include <iostream>
#include <SDL2/SDL.h>
#include "base/GameWindowResolutionSetup.cpp"
using namespace std; 

int main(int, char**){
    
    SDL_Window *window = nullptr; 

    GameWindowResolutionSetup *opGameWindowResolution = new GameWindowResolutionSetup();

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout<< "Initialization Error Encoutered: " << SDL_GetError() << endl; 
    }
    else
    {
        window = SDL_CreateWindow("Tetris in C++ by Ajinkya Joshi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, opGameWindowResolution->get_y_screen_resolution(), opGameWindowResolution->get_x_screen_resolution(), SDL_WINDOW_SHOWN);
        delete opGameWindowResolution; 
        if(window == NULL)
        {
            cout<< "Window Creation Error Encountered: " << SDL_GetError() << endl;
        } 
        else
        {
            SDL_UpdateWindowSurface(window);
            SDL_Delay(1000);
        }
    }

    SDL_DestroyWindow(window); 
    SDL_Quit();
    
    
    return 0; 

}
