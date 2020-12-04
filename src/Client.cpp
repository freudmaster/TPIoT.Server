//
// Created by MAGUENDJI Freud on 11/17/20.
//

#include "../include/Client.h"
#include <iostream>
#define BUFFER_SIZE 42


Client::Client(const sockaddr_in &clientAddr, int sockfd,Uint32 eventtype) : client_addr(clientAddr), sockfd(sockfd) {
    this->length = sizeof(client_addr);
    clientEventType = eventtype;
}
Client::Client(const sockaddr_in &clientAddr, socklen_t length, int sockfd, Uint32 eventtype) : client_addr(clientAddr), sockfd(sockfd){
    this->length = sizeof(client_addr);
    clientEventType = eventtype;
}
int Client::thread_task(void *data) {
    Client *client=(Client*)data;
    while (client->isConnected())
    {
        int bytesAvailable;
        ioctl(client->getSockfd(),FIONREAD , &bytesAvailable);
        if(bytesAvailable>0) {
            char recvbuf[bytesAvailable];
            int rcv = recv(client->getSockfd(), recvbuf, sizeof(recvbuf), 0);

            if (rcv > 0) {
                try {
                    auto j = json::parse(recvbuf);
                    auto point = Point::fromJson(j);
                    if (point != nullptr && *point != ZERO) {
                        client->sendPointMessage(point);
                    }
                } catch (json::exception &e) {}
            }
        }
        SDL_Delay(10);
    }
    return 0;
}

Client::Client(const sockaddr_in &clientAddr, socklen_t length, int sockfd) : client_addr(clientAddr), length(length),
                                                                              sockfd(sockfd) {}

void Client::startLooking() {
    std::string f("fclient");
    f+=std::to_string(rand()%1000);
    this->thread=SDL_CreateThread(thread_task,f.c_str(),this);
    if(this->thread!=0){

    }

}

const sockaddr_in &Client::getClientAddr() const {
    return client_addr;
}

void Client::setClientAddr(const sockaddr_in &clientAddr) {
    client_addr = clientAddr;
}

socklen_t Client::getLength() const {
    return length;
}

void Client::setLength(socklen_t length) {
    Client::length = length;
}

int Client::getSockfd() const {
    return sockfd;
}

void Client::setSockfd(int sockfd) {
    Client::sockfd = sockfd;
}

bool Client::isConnected() {
    int error = 0;
    socklen_t len = sizeof (error);
    getsockopt (this->getSockfd(), SOL_SOCKET, SO_ERROR, &error, &len);
    return error==0;
}

Client::~Client() {
    if(thread!= nullptr){
        SDL_DetachThread(thread);
        delete thread;
    }

}

void Client::sendPointMessage(Point *pPoint) {
    if (clientEventType != ((Uint32)-1)) {
        SDL_Event event;
        SDL_zero(event);
        event.type = clientEventType;
        event.user.code = 10;
        event.user.data1=(void *)pPoint;
        SDL_PushEvent(&event);
    }
}

void Client::disconnect() {
    SDL_DetachThread(thread);
    close(sockfd);

}

void Client::updateWindowSize(int width, int height) const {
    json json1;
    json1["width"]=width;
    json1["height"]=height;
    auto str=json1.dump();
    auto lenght=str.size();
    send(sockfd,str.c_str(),lenght,0);

}


