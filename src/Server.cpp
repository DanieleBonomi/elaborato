//
// Created by user on 21/06/2023.
//

#include <iostream>
#include "../headers/Server.h"
#include "../headers/Chat.h"

Server::Server(int maxChats) : maxChats(maxChats) {
usedID=0;
}

void Server::addChat(Chat *chat) {
    chats[chat->channel] = chat;
}

void Server::removeChat(int channel) {
chats.erase(channel);
}

Chat * Server::getChatAtChannel(int channel) const{
    return chats.at(channel);
}

int Server::getFreeId() {
    int t = usedID;
    usedID++;
    return t;
}

Server *Server::getInstance() {
    if (instance==nullptr) {
        instance = new Server(10);
    }
    return instance;
}

std::unique_ptr<Message> Server::onMessageReceived(std::unique_ptr<Message> m) {
    std::cout<<"Server <-" <<m->getSender()->getUsername() << ": " <<m->getText()<< std::endl;
    return m;
}

void Server::addUser(User *user) {
    users.push_back(user);
}

void Server::removeUser(User *user) {
    users.remove(user);
}
