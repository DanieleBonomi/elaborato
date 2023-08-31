//
// Created by user on 21/06/2023.
//

#include <iostream>
#include "../headers/Server.h"
#include "../headers/Chat.h"

void Server::addChat(int channel) {
    if (chats.size() < maxChats) {
        Chat *c = new Chat(channel);
        c->subscribe(this);
        chats.insert({channel, c});
    } else std::cout<<"WARNING: chat limit reached"<<std::endl;

    if (messageLog.find(channel) != messageLog.end()) {
        throw std::runtime_error("Creating chat at same channel (" + std::to_string(channel) + ") twice!");
    }
    messageLog[channel].clear(); //used
}

void Server::removeChat(int channel) {
    bool in = false;
    for (auto el : chats) {
        if (el.first==channel) {
            in = true;

        }
    }
    if (in) {
        chats.erase(channel);
    } else throw std::runtime_error("Attempting to remove chat not present in chats");
}

Chat * Server::getChatAtChannel(int channel) const{
    return chats.at(channel);
}

int Server::getFreeId() {
    int t = usedID;
    usedID++;
    return t;
}


std::unique_ptr<Message> Server::onMessageReceived(std::unique_ptr<Message> m) {
    std::cout<<"Server <-" <<m->getSender()->getUsername() << ": " <<m->getText()<< std::endl;

    Message * mex = new Message(*m);
    messageLog[mex->getChannel()].push_back(mex);
    //mex-> channel will be still stored in messageLog chat even if irrelevant

    return m;
}

void Server::addUser(std::string &username) {
    User * u = new User(username,this);
    users.push_back(u);
}

void Server::removeUser(User *user) {
    bool in = false;
    for (auto el : users) {
        if (el == user) {
            in = true;
        }
    }
    if (in)
    {
        users.remove(user);
    } else { throw std::runtime_error("Attempting to remove chat not present in chats");}
}

Server::~Server() {
    users.clear();
    chats.clear();
    messageLog.clear();
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

void Server::printAllChats() {
    std::cout<< "Printing messages from all chats:" << std::endl;
    for (const auto & chatIterator : messageLog){
        std::cout << "Chat at channel " << chatIterator.first << std::endl;
        for (const auto & messageIterator : chatIterator.second)
        {
            std::cout << messageIterator->getSender()->getUsername() << ": " << messageIterator->getText() << std::endl;
        }
    }
}

Server::Server(int maxChats) : maxChats(maxChats) {}

std::list<Message *> Server::getMessageFromChat(int channel) const {
    return messageLog.at(channel);
}

