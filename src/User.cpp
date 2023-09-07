//
// Created by user on 21/06/2023.
//

#include <iostream>
#include <utility>
#include "../headers/User.h"


User::User(const std::string username, Server* server) : username(username), server(server){
    id = server->getFreeId();
    verbose = server->isVerbose();
}

void User::openChat(int channel) {
    server->getChatAtChannel(channel)->subscribe(this);
}

void User::closeChat(int channel) {
    server->getChatAtChannel(channel)->unsubscribe(this);
}

void User::openChat(Chat *chat) {
    openChat(chat->getChannel());
}
void User::closeChat(Chat *chat) {
    closeChat(chat->getChannel());
}

int User::getId() const {
    return id;
}

const std::string &User::getUsername() const {
    return username;
}

void User::writeMessage(const std::string &text, int channel) {
    if (verbose)
        std::cout<< username << " -> " << text << " in channel " << channel << std::endl;
    server->getChatAtChannel(channel)->send(text, this);

}

std::unique_ptr<Message> User::onMessageReceived(std::unique_ptr<Message> m) { //FIXME message might be better as share_ptr, instead of being passed around
    if (verbose) {
        std::cout << username << " <- " << m->getSender()->getUsername() << ": " << m->getText() << std::endl;
    }
    return m;
}

bool User::isVerbose() const {
    return verbose;
}

void User::setVerbose(bool verbose) {
    User::verbose = verbose;
}
