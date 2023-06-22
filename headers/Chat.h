//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_CHAT_H
#define ELABORATO_CHAT_H


#include "Message.h"
#include "MessageReceiver.h"
#include <memory>

class Chat {

public:
    explicit Chat(int channel);
    void send(std::string m, User * user);
    void subscribe(std::shared_ptr<MessageReceiver> user);
    void unsubscribe(std::shared_ptr<MessageReceiver> user);

public:
    int channel;
    std::list<std::shared_ptr<MessageReceiver>> users;
};


#endif //ELABORATO_CHAT_H
