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

void Chat::send(Message message) {
    // check if user is in chat
    if (std::find(receivers.begin(), receivers.end(), message.getSender())!=receivers.end()) { //sends message back to sender as well. Could be useful for checking if message failed
        for (auto item: receivers) {
            item->onMessageReceived(message);
        }
    }
}

void Chat::send(const std::string &text, User * user) {
    Message m = Message(text,user,channel);
    send(m);
}

int Chat::getChannel() const {
    return channel;
}
