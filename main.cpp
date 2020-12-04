#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "SDL.h"
#include "SDL2/SDL_ttf.h"

#include "TPViewWindow.h"
#include "Server.h"

// Window dimensions
static const int width = 800;
static const int height = 600;

int main(int argc, char **argv) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        exit(-1);
    if (TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        return EXIT_FAILURE;
    }
    TPViewWindow *tpViewWindow=new TPViewWindow(width,height,"TP.IoT");
    Server server;
    tpViewWindow->setServer(&server);
    tpViewWindow->show();
    delete tpViewWindow;
    tpViewWindow= nullptr;
    TTF_Quit();
    SDL_Quit();

    return 0;
}