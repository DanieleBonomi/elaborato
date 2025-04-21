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

void User::onMessageReceived(std::shared_ptr<Message> message) {
    if (message->getSender()==this) { // If this user sent the message, no need to read it
        message->setRead(this);
    }
    unreadMessages.push_back(message);
}

bool User::isVerbose() const {
    return verbose;
}

void User::setVerbose(bool verbose) {
    User::verbose = verbose;
}

void User::readAll() {
    for (const auto& el: unreadMessages) {
        el->setRead(this);
        if (verbose) {
            std::cout << username << " <- " << el->getSender()->getUsername() << ": " << el->getText() << std::endl;
        }
    }
}
