//
// Created by user on 21/06/2023.
//

#include "../headers/Server.h"

Server::Server(int maxChats) : maxChats(maxChats) {
usedID=0;
}

void Server::addChat(std::shared_ptr<Chat> chat) {
    chats[chat->channel] = chat;
}

void Server::removeChat(int channel) {
chats.erase(channel);
}

std::shared_ptr<Chat> Server::getChatAtChannel(int channel) const{
    return chats.at(channel);
}

int Server::getFreeId() {
    int t = usedID;
    usedID++;
    return t;
}

std::shared_ptr<Server> Server::getIstance() {
    if (instance==nullptr) {
        instance = std::shared_ptr<Server>(new Server(10));
    }
    return instance;
}
