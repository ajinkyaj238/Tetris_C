#include<iostream>
#include<SDL2/SDL.h>
#include<string>


#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <CoreGraphics/CoreGraphics.h>
#elif __linux__
#include <X11/Xlib.h>
#endif

// Hungarian notation used for variables
// Pascalcase notation used for Classes
// Snakecase used for functions/methods
// Trying out structs and classes

class GameWindowResolutionSetup
{
public:
    int iXScreenResolution; 
    int iYScreenResolution;

    GameWindowResolutionSetup();

    int get_x_screen_resolution(); 
    int get_y_screen_resolution();
    void checker();


};

GameWindowResolutionSetup::GameWindowResolutionSetup(){
    
    // windows resolution
    #ifdef _WIN32
        RECT desktop;
        const HWND hDesktop = GetDesktopWindow();
        GetWindowRect(hDesktop, &desktop);
        iYScreenResolution = desktop.right;
        iXScreenResolution = desktop.bottom;

    #elif __APPLE__
        CGDirectDisplayID displayID = kCGDirectMainDisplay;
        CGRect screenBounds = CGDisplayBounds(displayID);
        iYScreenResolution = static_cast<int>(CGRectGetWidth(screenBounds));
        iXScreenResolution = static_cast<int>(CGRectGetHeight(screenBounds));

    #elif __linux__
        Display* d = XOpenDisplay(NULL);
        Screen*  s = DefaultScreenOfDisplay(d);
        iYScreenResolution = s->width;
        iXScreenResolution = s->height;
        XCloseDisplay(d);
    #endif

}

int GameWindowResolutionSetup::get_x_screen_resolution()
{
    return iXScreenResolution; // 1080
}

int GameWindowResolutionSetup::get_y_screen_resolution()
{
    return iYScreenResolution; //1920
}

void GameWindowResolutionSetup::checker(){
    std::cout<< "Hey from GameWindowResolution Class" << std::endl; 
}


