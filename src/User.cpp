//
// Created by user on 21/06/2023.
//

#include <iostream>
#include "../headers/User.h"


User::User(const std::string &username) : username(username) {
    id = Server::getInstance()->getFreeId();
}

void User::openChat(int channel) {
    Server::getInstance()->getChatAtChannel(channel)->subscribe(this);
}

void User::closeChat(int channel) {
    Server::getInstance()->getChatAtChannel(channel)->unsubscribe(this);
}

void User::openChat(Chat *chat) {
    openChat(chat->channel);
}
void User::closeChat(Chat *chat) {
    closeChat(chat->channel);
}

int User::getId() const {
    return id;
}

const std::string &User::getUsername() const {
    return username;
}

void User::writeMessage(const std::string &text, int channel) {
    std::cout<< username << " -> " << text << " in channel " << channel << std::endl;
    Server::getInstance()->getChatAtChannel(channel)->send(text, this);

}

std::unique_ptr<Message> User::onMessageReceived(std::unique_ptr<Message> m) {
    std::cout<< username <<" <- " <<m->getSender()->getUsername() << ": " <<m->getText()<< std::endl;
    return m;
}
