//
// Created by MAGUENDJI Freud on 11/17/20.
//

#ifndef TP_IOT_SERVER_H
#define TP_IOT_SERVER_H
#include <string>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "SDL.h"
#define PORT 8081
#define MAXLINE 1024
#include "Client.h"
#include <iostream>
#include <string>
#include <list>
class Server {
public:
    enum ServerState{
        START=1,RUNNING=3,STOP=2,PAUSE=-1, INITIALISATION=0
    };
    enum ServerMessage{
        ACCEPTING_CLIENT,SENDING_DATA,RECEIVING_DATA,IDLE
    };
    Server();
    void startListen();
    static void runningServeur(Server *self);

    ServerState getStateServeur() const;

    virtual ~Server();

    void setStateServeur(ServerState stateServeur);

    bool isRunning() const;
    int getPort();
    std::string getIpAddress() const;
    void setRunning(bool running);

    int countClients();

    void closeServeur();

    void updateWindowSize(int width, int height);

private:
    int sockfd;
    int* buffer;
    bool running;

    std::thread* serveurThread;
    struct sockaddr_in servaddr, cliaddr;
    std::list<Client*> clients;
    ServerState stateServeur;

    void sendMessageServeur(ServerMessage message);

    Uint32 serverEventType;

    void addClient(Client *pClient);
};


#endif //TP_IOT_SERVER_H
