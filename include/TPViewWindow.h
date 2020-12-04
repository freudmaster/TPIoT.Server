//
// Created by MAGUENDJI Freud on 11/27/20.
//

#ifndef TP_IOT_TPVIEWWINDOW_H
#define TP_IOT_TPVIEWWINDOW_H
#include "SDL.h"
#include "SDL2/SDL_ttf.h"
#include <thread>
#include <vector>
#include <string>
#include "Server.h"

class TPViewWindow {
public:
    TPViewWindow(int width, int height);

    TPViewWindow(int width, int height, const std::string &title);

    void show();
    virtual ~TPViewWindow();

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    void setServer(Server *server);

    SDL_Window *getWindow() const;

    SDL_Renderer *getRenderer() const;

    bool isRunning() const;

    void setRunning(bool running);
    void blockingForExit();


private:
    int width_;
    int height_;
    bool running;
    std::thread *thread= nullptr;
    SDL_Window *window= nullptr;
    SDL_Renderer *renderer= nullptr;
    std::string title_;
    Server* server_= nullptr;
    SDL_Texture *textureInformation= nullptr;
    SDL_Texture *texturePoint= nullptr;
    TTF_Font* font= nullptr;
    SDL_Texture *textureOptions= nullptr;
    std::vector<Point*> points;
    std::vector<SDL_Point> pointsList;
    void cleanUp(bool needClear);

    void showServeurInformations();

    void handleUserEvent(SDL_Event *pEvent);

    void handleServeurStateChange(Sint32 code);

    void updateServerState(const std::string &str);

    void showServerConnectedState();

    void handlePointReceive(Point *pPoint);

    void showPoints();

    SDL_Color getColorFrom(int i);

    void windowChange(SDL_Event *pEvent);
};


#endif //TP_IOT_TPVIEWWINDOW_H
