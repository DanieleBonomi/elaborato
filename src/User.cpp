//
// Created by user on 21/06/2023.
//

#include "../headers/User.h"


User::User(const std::string &username) : username(username) {
    id = Server::getInstance()->getFreeId();
}

void User::openChat(int channel) {
    Server::getInstance()->getChatAtChannel(channel)->subscribe(std::shared_ptr<User>(this));
}

void User::closeChat(int channel) {
    Server::getInstance()->getChatAtChannel(channel)->unsubscribe(std::shared_ptr<User>(this));
}

void User::openChat(std::shared_ptr<Chat> chat) {
    openChat(chat->channel);
}
void User::closeChat(std::shared_ptr<Chat> chat) {
    closeChat(chat->channel);
}

void User::writeMessage(const std::string &text) const {
    chat.send()
}

