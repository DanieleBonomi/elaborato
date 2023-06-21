//
// Created by user on 21/06/2023.
//

#include <algorithm>
#include "../headers/Chat.h"

Chat::Chat(int channel) : channel(channel) {}

void Chat::send(Message &m) {
    for (const auto & item : users)
        item->onMessageReceived(m);

}

void Chat::subscribe(std::shared_ptr<MessageReceiver> user) {
    if (std::find(users.begin(),users.end(),user)!=users.end()) {
        users.push_back(user);
    }
}

void Chat::unsubscribe(std::shared_ptr<MessageReceiver> user) {
    if (std::find(users.begin(),users.end(),user)==users.end()) {
        users.remove(user);
    }
}
