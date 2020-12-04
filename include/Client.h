//
// Created by MAGUENDJI Freud on 11/17/20.
//

#ifndef TP_IOT_CLIENT_H
#define TP_IOT_CLIENT_H
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
#include <nlohmann/json.hpp>
#include "Point.h"
#include <sys/select.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <SDL.h>
#include <SDL2/SDL_thread.h>
using json = nlohmann::json;
class Client {
public:
    Client(const sockaddr_in &clientAddr, int sockfd,Uint32 eventtype);

    Client(const sockaddr_in &clientAddr, socklen_t length, int sockfd);
    Client(const sockaddr_in &clientAddr, socklen_t length,int sockfd,Uint32 eventtype);

    void startLooking();

    virtual ~Client();

    const sockaddr_in &getClientAddr() const;

    void setClientAddr(const sockaddr_in &clientAddr);

    socklen_t getLength() const;

    void setLength(socklen_t length);

    int getSockfd() const;

    void setSockfd(int sockfd);

    void disconnect();

    void updateWindowSize(int width, int height) const;

private:
    void lookingForData();
    struct sockaddr_in client_addr;
    socklen_t length;
    int sockfd;
    SDL_Thread *thread=NULL;
    Uint32 clientEventType;
    static int thread_task(void *data);

    bool isConnected();

    void sendPointMessage(Point *pPoint);
};


#endif //TP_IOT_CLIENT_H
