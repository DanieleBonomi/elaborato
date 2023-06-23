//
// Created by user on 21/06/2023.
//

#include <algorithm>
#include "../headers/Chat.h"


Chat::Chat(int channel) : channel(channel) {}


void Chat::subscribe(MessageReceiver *user) {
    if (std::find(users.begin(),users.end(),user)!=users.end()) {
        users.push_back(user);
    }
}

void Chat::unsubscribe(MessageReceiver *user) {
    if (std::find(users.begin(),users.end(),user)==users.end()) {
        users.remove(user);
    }
}

void Chat::send(std::unique_ptr<Message> message) {
    for (auto item : users)
    {
        message = item->onMessageReceived(std::move(message));
    }

}

void Chat::send(const std::string &text, User * user) {
    std::unique_ptr<Message> m = std::make_unique<Message>(Message(text,user));
    send(std::move(m));
}
