//
// Created by user on 21/06/2023.
//

#include <algorithm>
#include <iostream>
#include <utility>
#include "../headers/Chat.h"


Chat::Chat(int channel) : channel(channel) {}


void Chat::subscribe(MessageReceiver *user) {
    if (std::find(receivers.begin(), receivers.end(), user) == receivers.end()) {
        receivers.push_back(user);
    }
}

void Chat::unsubscribe(MessageReceiver *user) {
    if (std::find(receivers.begin(), receivers.end(), user) == receivers.end()) {
        receivers.remove(user);
    }
}

void Chat::send(std::unique_ptr<Message> message) {
    for (auto item : receivers)
    {
        message = item->onMessageReceived(std::move(message));
    }

}

void Chat::send(const std::string &text, User * user) {
    std::unique_ptr<Message> m = std::make_unique<Message>(Message(text,user,channel));
    send(std::move(m));
}

int Chat::getChannel() const {
    return channel;
}
