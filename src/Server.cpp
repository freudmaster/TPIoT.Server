//
// Created by MAGUENDJI Freud on 11/17/20.
//

#include "Server.h"

Server::Server() {
    this->sockfd= socket(AF_INET, SOCK_STREAM, 0);
    this->servaddr.sin_family = AF_INET;
    this->servaddr.sin_port = htons(PORT);
    this->servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverEventType = SDL_RegisterEvents(1);

}

void Server::startListen() {
    serveurThread=new std::thread(&Server::runningServeur,this);

}

void Server::runningServeur(Server *self) {
    self->setStateServeur(ServerState::INITIALISATION);
    if (bind(self->sockfd, (struct sockaddr *) &self->servaddr, sizeof(self->servaddr)) == -1) {
        perror("bind");
        exit(1);
    }
    std::this_thread::sleep_for (std::chrono::seconds(2));
    self->setStateServeur(ServerState::START);
    if (listen(self->sockfd, 1) == -1) {
        perror("listen");
        exit(1);
    }
    std::this_thread::sleep_for (std::chrono::seconds(2));
    self->setStateServeur(ServerState::RUNNING);
    while (self->isRunning()){
        struct sockaddr_in client_addr;
        socklen_t length = sizeof(client_addr);
        int conn = accept(self->sockfd, (struct sockaddr *) &client_addr, &length);
        if (conn < 0) {
            exit(1);
        }
        self->sendMessageServeur(ServerMessage::ACCEPTING_CLIENT);
        auto *client=new Client(client_addr, length, conn,self->serverEventType);
        client->startLooking();
        self->addClient(client);

        std::this_thread::sleep_for (std::chrono::seconds(4));
        self->sendMessageServeur(ServerMessage::IDLE);
    }
}

bool Server::isRunning() const {
    return running;
}

void Server::setRunning(bool running) {
    Server::running = running;
}

int Server::getPort() {
    return PORT;
}

std::string Server::getIpAddress() const {
    return std::string();
}

void Server::sendMessageServeur(Server::ServerMessage message) {

    if (serverEventType != ((Uint32)-1)) {
        SDL_Event event;
        SDL_zero(event);
        event.type = serverEventType;
        switch (message) {
            case ACCEPTING_CLIENT:
                event.user.code = 1;
                break;
            case SENDING_DATA:
                event.user.code = -1;
                break;
            case RECEIVING_DATA:
                event.user.code = 2;
                break;

        }
        SDL_PushEvent(&event);
    }

}

Server::ServerState Server::getStateServeur() const {
    return stateServeur;
}

void Server::setStateServeur(Server::ServerState stateServeur) {
    if(stateServeur!=Server::stateServeur) {
        setRunning(stateServeur==RUNNING);
        Server::stateServeur = stateServeur;

    }

}

Server::~Server() {
    setRunning(false);
    setStateServeur(ServerState::STOP);

    if (serveurThread!= nullptr ) {
        serveurThread->detach();
        delete serveurThread;
    }
    if(!clients.empty()){
        for(auto i =clients.begin();i!=clients.end();i++)
            i.operator*()->disconnect();

    }

}

void Server::addClient(Client *pClient) {
    clients.push_back(pClient);
}

int Server::countClients() {
    return clients.size();
}

void Server::closeServeur() {
    for(auto i=clients.begin();i!=clients.end();i++){
        i.operator*()->disconnect();
    }
    serveurThread->detach();
    close(sockfd);

}

void Server::updateWindowSize(int width, int height) {
    for(auto i=clients.begin();i!=clients.end();i++)
        i.operator*()->updateWindowSize(width,height);


}

