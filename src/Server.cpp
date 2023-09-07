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
    if (verbose) {
        std::cout << "Server <-" << m->getSender()->getUsername() << ": " << m->getText() << std::endl;
    }

    auto * mex = new Message(*m);
    messageLog[mex->getChannel()].push_back(mex);
    //mex-> channel will be still stored in messageLog chat even if irrelevant

    return m;
}

int Server::addUser(std::string &username) {
    for (const auto & el: users) {
        if (el->getUsername()==username)
            throw std::runtime_error("User with name: " + username + " already in users");
    }
    User * u = new User(username,this);
    users.push_back(u);
    return u->getId();
}

void Server::removeUser(int id) {

    bool found = false;
    for (const auto & el: users) {
        if (el->getId()==id)
        {
            users.remove(el);
            found=true;
            break;
        }
    }
    if (!found)
        throw (std::runtime_error("User can't be removed because there's no user at id"));

}

Server::~Server() {
    users.clear();
    chats.clear();
    for (auto & el: messageLog) {
        el.second.clear();
    }
    messageLog.clear();
}



void Server::signToChat(int id, int channel) {
    chats[channel]->subscribe(getUserAtId(id));
}

void Server::signAllToChat(int channel) {
    Chat * c = chats[channel];
    for (auto user : users)
        c->subscribe(user);
}

User *Server::getUserAtUsername(const std::string &username) const {
    for (auto user : users) {
        if (user->getUsername() == username) {
            return user;
        }
    }
    throw std::runtime_error("No user at username");
}

User * Server::getUserAtId(int id) const {
    for (auto user : users) {
        if (user->getId() == id) {
            return user;
        }
    }
    throw std::runtime_error("No user at id");
}

void Server::printAllChats() {
    if (verbose) {
        std::cout << "Printing messages from all chats:" << std::endl;
        for (const auto &chatIterator: messageLog) {
            std::cout << "Chat at channel " << chatIterator.first << std::endl;
            for (const auto &messageIterator: chatIterator.second) {
                std::cout << messageIterator->getSender()->getUsername() << ": " << messageIterator->getText()
                          << std::endl;
            }
        }
    }
}

Server::Server(int maxChats, bool verbose) : maxChats(maxChats), verbose(verbose) {}

std::list<Message *> Server::getMessageFromChat(int channel) const {
    return messageLog.at(channel);
}

bool Server::isVerbose() const {
    return verbose;
}

void Server::setVerbose(bool verbose) {
    Server::verbose = verbose;
    for (auto el: users) {
        el->setVerbose(verbose);
    }
}


