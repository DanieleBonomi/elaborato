//
// Created by user on 21/06/2023.
//

#include <algorithm>
#include "../headers/Chat.h"

Chat::Chat(int channel) : channel(channel) {}


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

void Chat::send(std::string m, User *user) {
    for (auto item : users)
    {
        item->
    }

}
