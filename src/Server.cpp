//
// Created by user on 21/06/2023.
//

#include <iostream>
#include "../headers/Server.h"
#include "../headers/Chat.h"

Server::Server() {
usedID=0;
maxChats = 10;
}

void Server::addChat(int channel) {
    if (chats.size() < maxChats) {
        Chat *c = new Chat(channel);
        c->subscribe(this);
        chats.insert({channel, c});
    } else std::cout<<"WARNING: chat limit reached"<<std::endl;
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
        instance = new Server();
    }
    return instance;
}

std::unique_ptr<Message> Server::onMessageReceived(std::unique_ptr<Message> m) {
    std::cout<<"Server <- " <<m->getSender()->getUsername() << ": " <<m->getText()<< std::endl;
    return m;
}

void Server::addUser(std::string &username) {
    User * u = new User(username);
    users.push_back(u);
}

void Server::removeUser(User *user) {
    users.remove(user);
}

Server::~Server() {
    users.clear();
    chats.clear();
}

void Server::signToChat(std::string &username, int channel) {
    chats[channel]->subscribe(getUserAtUsername(username)); //TODO fix multiple username being considered as same User (in the whole project)
}

void Server::signAllToChat(int channel) {
    Chat * c = chats[channel];
    for (auto user : users)
        c->subscribe(user);
}

User *Server::getUserAtUsername(std::string &username) {
    for (auto user : users) {
        if (user->getUsername() == username) {
            return user;
        }
    }
    throw std::exception();
}

