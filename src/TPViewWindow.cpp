//
// Created by MAGUENDJI Freud on 11/27/20.
//

#include "TPViewWindow.h"

TPViewWindow::TPViewWindow(int width, int height) : width_(width), height_(height) {
    thread= nullptr;

}

TPViewWindow::~TPViewWindow() {
    if(font!= nullptr) {
        TTF_CloseFont(font);
        font= nullptr;
    }
    if(textureInformation!= nullptr) {
        SDL_DestroyTexture(textureInformation);
        textureInformation= nullptr;
    }
    if(textureOptions!= nullptr) {
        SDL_DestroyTexture(textureOptions);
        textureOptions= nullptr;
    }
    if (texturePoint!= nullptr) {
        SDL_DestroyTexture(texturePoint);
        texturePoint= nullptr;
    }
    if(renderer!= nullptr) {
        SDL_DestroyRenderer(renderer);
        renderer= nullptr;
    }
    if(window!= nullptr) {
        SDL_DestroyWindow(window);
        window= nullptr;
    }
}

void TPViewWindow::show() {
    window = SDL_CreateWindow(title_.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    font = TTF_OpenFont("../fonts/Montserrat/Montserrat-Regular.ttf", 12);
    if(window== nullptr){
        exit(-1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer== nullptr){
        exit(-1);
    }
    textureInformation = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, getWidth(), (int)(height_*.33));

    if(thread!= nullptr){
        thread->join();
    }
    blockingForExit();
    //thread=new std::thread(lookingKey,*this);
}

int TPViewWindow::getWidth() const {
    return width_;
}

void TPViewWindow::setWidth(int width) {
    width_ = width;

}

int TPViewWindow::getHeight() const {
    return height_;
}

void TPViewWindow::setHeight(int height) {
    height_ = height;
}

bool TPViewWindow::isRunning() const {
    return running;
}

void TPViewWindow::setRunning(bool running) {
    TPViewWindow::running = running;
}

SDL_Window *TPViewWindow::getWindow() const {
    return window;
}

SDL_Renderer *TPViewWindow::getRenderer() const {
    return renderer;
}

void TPViewWindow::blockingForExit() {

    setRunning(true);
    SDL_Event event;
    while(isRunning()) {
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderClear(getRenderer());
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_USEREVENT:
                    handleUserEvent(&event);
                    break;
                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                            windowChange(&event);
                    break;
                case SDL_QUIT:
                    setRunning(false);
                    break;
            }
        }

        showServeurInformations();
        showPoints();
        cleanUp(false);
        SDL_Delay(10);
    }
}

TPViewWindow::TPViewWindow(int width, int height, const std::string &title) : width_(width), height_(height),title_(title) {
    thread = nullptr;
}
void TPViewWindow::setServer(Server *server) {
    server_ = server;
    server->startListen();
}

void TPViewWindow::cleanUp(bool needClear) {
    if(needClear)
        SDL_RenderClear(getRenderer());
    SDL_RenderPresent(getRenderer());
}

void TPViewWindow::showServeurInformations() {
    std::string txt="Bienvenue dans le TP.IoT";
    SDL_Surface* text = TTF_RenderText_Blended(font, "Bienvenue dans le TP.IoT", SDL_Color{ 0, 0, 0, 255 });
    SDL_Texture *t=SDL_CreateTextureFromSurface(renderer,text);
     SDL_Rect position;
    position.h=text->h;
    position.w=text->w;
    position.x=10;
    position.y=(int)(position.h*0.5);;
    SDL_SetRenderDrawColor(getRenderer(), 0, 255, 0, 255);
    SDL_RenderCopy(getRenderer(), t, nullptr, &position);
    SDL_FreeSurface(text);
    SDL_DestroyTexture(t);
    text= nullptr;
    t= nullptr;
    if (server_->isRunning())
      showServerConnectedState();
    handleServeurStateChange(server_->getStateServeur());

}

void TPViewWindow::handleUserEvent(SDL_Event *pEvent) {
    auto userEvent=(SDL_UserEvent*)pEvent;
    if(userEvent!= nullptr){
        switch (userEvent->code) {
            case -1:
            case 0:
            case 1:
            case 2: //handleServeurStateChange(userEvent->code);
                break;
            case 10:
                handlePointReceive((Point *)userEvent->data1);
        }
    }

}

void TPViewWindow::handleServeurStateChange(Sint32 code) {
    std::string textServeurState;
    switch (code) {
        case 0:textServeurState="Initialisation du serveur";break;
        case -1:textServeurState="Le serveur est en pause";break;
        case 1:textServeurState="Le serveur demarre";break;
        case 3:textServeurState="Le serveur est en cours d'execution sur le port "+std::to_string(server_->getPort());break;
        case 2:textServeurState="Le serveur est arrété";break;
    }
    if(textServeurState.length()>0)
        updateServerState(textServeurState);


}

void TPViewWindow::updateServerState(const std::string&  str) {
    SDL_Surface* text = TTF_RenderText_Blended(font, str.c_str(), SDL_Color{ 0, 0, 0, 255 });
    SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,text);
    SDL_Rect position;
    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
    position.x=10;
    position.y=(int)(position.h*1.5);

    SDL_FreeSurface(text);
    SDL_SetRenderDrawColor(getRenderer(), 0, 255, 0, 255);
    SDL_RenderCopy(getRenderer(), texture, nullptr, &position);
    SDL_DestroyTexture(texture);
    text= nullptr;
    texture= nullptr;

}

void TPViewWindow::showServerConnectedState() {
    SDL_Surface* text = TTF_RenderText_Blended(font, std::string(std::to_string(server_->countClients())+" Appareil(s) Connect\x82(s)").c_str(), SDL_Color{ 0, 0, 0, 255 });
    SDL_Texture* texture = SDL_CreateTextureFromSurface(getRenderer(), text);
    SDL_Rect position;
    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
    position.x=getWidth()-(10+position.w);
    position.y=(int)(position.h*0.5);;
    SDL_FreeSurface(text);
    SDL_SetRenderDrawColor(getRenderer(), 0, 255, 0, 255);
    SDL_RenderCopy(getRenderer(), texture, nullptr, &position);
    SDL_DestroyTexture(texture);
    text= nullptr;
    texture= nullptr;

}

void TPViewWindow::handlePointReceive(Point *pPoint) {
    if(pPoint!= nullptr){
        bool found=false;
        for(auto i=points.begin();i!=points.end();++i){
            if(*i.operator*()==*pPoint){
                found=true;
                break;
            }
        }
        if(!found){
            points.push_back(pPoint);
            pointsList.push_back(SDL_Point{(int)pPoint->getX(),(int)pPoint->getY()});
        }
    }

}

void TPViewWindow::showPoints() {
    SDL_SetRenderDrawColor(getRenderer(),0,0,0,255);
    if(pointsList.size()>1) {
        for (int i = 0; i < pointsList.size() - 1; i++) {
            auto first = pointsList.at(i);
            auto second = pointsList.at(i + 1);
            SDL_Color color = getColorFrom(i);
            SDL_SetRenderDrawColor(getRenderer(), color.r, color.g, color.b, color.a);
            SDL_RenderDrawLine(getRenderer(), first.x, first.y, second.x, second.y);
        }
    }
    //SDL_RenderDrawLines(getRenderer(),&pointsList[0],pointsList.size());
}

SDL_Color TPViewWindow::getColorFrom(int i) {
    auto col_str=points.at(i)->getColor();
    std::string valeur;
    int posi=0,r_,g_,b_;
    for(int j=0;j<col_str.size();j++){
        char c=col_str.at(j);
        if(c=='.'){
            if (posi==0)
                r_=std::stoi(valeur);
            else if(posi==1)
                g_=std::stoi(valeur);
            else if (posi==2) {
                b_ = std::stoi(valeur);
                break;
            }
            posi++;
            valeur.clear();
        }else
            valeur+=c;
    }
        SDL_Color color{(Uint8)r_,static_cast<Uint8>(g_),static_cast<Uint8>(b_),255};
    return color;
}

void TPViewWindow::windowChange(SDL_Event *pEvent) {
    if(pEvent!= nullptr){
        setWidth(pEvent->window.data1);
        setHeight(pEvent->window.data2);
        if(server_!= nullptr){
            server_->updateWindowSize(getWidth(),getHeight());
        }
    }

}


